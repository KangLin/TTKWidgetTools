#ifndef TTKANY_H
#define TTKANY_H

/***************************************************************************
 * This file is part of the TTK Library Module project
 * Copyright (C) 2015 - 2023 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include <memory>
#include <typeindex>
#include "ttkglobaldefine.h"

/*! @brief The class of the ttk any model.
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKAny
{
public:
    TTKAny();
    TTKAny(const TTKAny &other);
    TTKAny(TTKAny &&other);

    template <typename T,
              typename = typename std::enable_if<!std::is_same<typename std::decay<T>::type, TTKAny>::value, T>::type>
    TTKAny(T &&t)
        : m_ptr(new _Derived<typename std::decay<T>::type>(std::forward<T>(t))),
          m_type(typeid(typename std::decay<T>::type))
    {

    }

    bool isNull() const;

    template <typename T>
    bool isSame() const
    {
        return m_type == std::type_index(typeid(T));
    }

    template <typename T>
    T &cast()
    {
        if(!isSame<T>())
        {
            throw std::bad_cast();
        }

        auto ptr = TTKDynamicCast(_Derived<T>*, m_ptr.get());
        return ptr->m_value;
    }

    template <typename T>
    const T &cast() const
    {
        if(!isSame<T>())
        {
            throw std::bad_cast();
        }

        auto ptr = TTKDynamicCast(_Derived<T>*, m_ptr.get());
        return ptr->m_value;
    }

    TTKAny &operator=(const TTKAny &other);

private:
    struct _Base;
    using _BasePtr = std::unique_ptr<_Base>;

    struct _Base
    {
        virtual _BasePtr clone() const = 0;
    };

    template <typename T>
    struct _Derived : public _Base
    {
        template <typename... Args>
        _Derived(Args &&...args)
            : m_value(std::forward<Args>(args)...)
        {
        }

        virtual _BasePtr clone() const override final
        {
            return _BasePtr(new _Derived<T>(m_value));
        }

        T m_value;
    };

    _BasePtr clone() const
    {
        return m_ptr ? m_ptr->clone() : nullptr;
    }

    _BasePtr m_ptr;
    std::type_index m_type;

};

#ifdef TTK_CAST
#  define TTKAnyCast(x, y) (TTK::any_cast<x>(y))
#else
#  define TTKAnyCast(x, y) ((x)(y))
#endif

namespace TTK
{
    template <typename T>
    using remove_cvr = typename std::remove_cv<typename std::remove_reference<T>::type>::type;

    template <typename T>
    inline remove_cvr<T> any_cast(const TTKAny &other)
    {
        using _Type = remove_cvr<T>;
        const auto ptr = any_cast<_Type>(&other);
        if(!ptr)
        {
            throw std::bad_cast();
        }
        return *ptr;
    }

    template <typename T>
    inline remove_cvr<T> any_cast(TTKAny &other)
    {
        using _Type = remove_cvr<T>;
        const auto ptr = any_cast<_Type>(TTKStaticCast(const TTKAny*, &other));
        if(!ptr)
        {
            throw std::bad_cast();
        }
        return *ptr;
    }

    template <typename T>
    inline remove_cvr<T> any_cast(TTKAny &&other)
    {
        using _Type = remove_cvr<T>;
        const auto ptr = any_cast<_Type>(TTKStaticCast(const TTKAny*, &other));
        if(!ptr)
        {
            throw std::bad_cast();
        }
        return std::move(*ptr);
    }

    template <typename T>
    inline const remove_cvr<T> *any_cast(const TTKAny *const other) noexcept
    {
        using _Type = remove_cvr<T>;
        return (!other || !other->isSame<_Type>()) ? nullptr : &other->cast<_Type>();
    }

    template <typename T>
    inline remove_cvr<T> *any_cast(TTKAny *const other) noexcept
    {
        using _Type = remove_cvr<T>;
        return TTKConstCast(_Type*, any_cast<_Type>(TTKStaticCast(const TTKAny*, other)));
    }

}

#endif // TTKANY_H

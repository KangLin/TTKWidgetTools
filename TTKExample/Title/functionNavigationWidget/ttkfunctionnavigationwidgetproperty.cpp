#include "ttkfunctionnavigationwidgetproperty.h"
#include "ttkfunctionnavigationwidget.h"

#include <QBoxLayout>

TTKFunctionNavigationWidgetProperty::TTKFunctionNavigationWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new QWidget(this);

    for(int i = 0; i < 5; ++i)
    {
        TTKFunctionNavigationWidget *button = new TTKFunctionNavigationWidget(this);
        button->setText(QString("%1%1%1%1%1").arg(i));
        m_buttons << button;

        connect(button, SIGNAL(clicked()), SLOT(buttonClicked()));
    }
    m_buttons[0]->setChecked(true);
}

void TTKFunctionNavigationWidgetProperty::buttonClicked()
{
    TTKFunctionNavigationWidget *button = TTKObject_cast(TTKFunctionNavigationWidget*, sender());
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        m_buttons[i]->setChecked(m_buttons[i] == button);
    }
}


//
TTKFunctionNavigationAWidgetProperty::TTKFunctionNavigationAWidgetProperty(QWidget *parent)
    : TTKFunctionNavigationWidgetProperty(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(m_item);
    layout->setSpacing(2);
    m_item->setLayout(layout);

    for(int i = 0; i < m_buttons.count(); ++i)
    {
        layout->addWidget(m_buttons[i]);
    }
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObject_cast(TTKFunctionNavigationWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *showIconItem = m_boolManager->addProperty("ShowIcon");
    m_boolManager->setValue(showIconItem, true);
    objectItem->addSubProperty(showIconItem);
    //
    QtProperty *iconSpaceItem = m_intManager->addProperty("IconSpace");
    m_intManager->setMinimum(iconSpaceItem, 0);
    m_intManager->setValue(iconSpaceItem, 15);
    objectItem->addSubProperty(iconSpaceItem);
    //
    QtProperty *iconSizeItem = m_sizeManager->addProperty("IconSize");
    m_sizeManager->setMinimum(iconSizeItem, QSize(0, 0));
    m_sizeManager->setValue(iconSizeItem, QSize(10, 10));
    objectItem->addSubProperty(iconSizeItem);
    //
    QtProperty *normalIconItem = m_colorManager->addProperty("NormalIcon");
    m_colorManager->setValue(normalIconItem, QColor(255, 255, 255));
    objectItem->addSubProperty(normalIconItem);
    //
    QtProperty *hoverIconItem = m_colorManager->addProperty("HoverIcon");
    m_colorManager->setValue(hoverIconItem, QColor(150, 150, 150));
    objectItem->addSubProperty(hoverIconItem);
    //
    QtProperty *checkIconItem = m_colorManager->addProperty("CheckIcon");
    m_colorManager->setValue(checkIconItem, QColor(50, 50, 50));
    objectItem->addSubProperty(checkIconItem);
    //
    QtProperty *paddingLeftItem = m_intManager->addProperty("PaddingLeft");
    m_intManager->setMinimum(paddingLeftItem, 0);
    m_intManager->setValue(paddingLeftItem, 32);
    objectItem->addSubProperty(paddingLeftItem);
    //
    QtProperty *lineSpaceItem = m_intManager->addProperty("LineSpace");
    m_intManager->setMinimum(lineSpaceItem, 0);
    m_intManager->setValue(lineSpaceItem, 6);
    objectItem->addSubProperty(lineSpaceItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKFunctionNavigationAWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "ShowIcon")
        {
            m_buttons[i]->setShowIcon(value);
        }
    }
}

void TTKFunctionNavigationAWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "IconSpace")
        {
            m_buttons[i]->setIconSpace(value);
        }
        else if(property->propertyName() == "PaddingLeft")
        {
            m_buttons[i]->setPaddingLeft(value);
        }
        else if(property->propertyName() == "LineSpace")
        {
            m_buttons[i]->setLineSpace(value);
        }
    }
}

void TTKFunctionNavigationAWidgetProperty::sizePropertyChanged(QtProperty *property, const QSize &value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "IconSize")
        {
            m_buttons[i]->setIconSize(value);
        }
    }
}

void TTKFunctionNavigationAWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    QPixmap pixmap(1, 1);
    pixmap.fill(value);
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "NormalIcon")
        {
            m_buttons[i]->setIconNormal(pixmap);
        }
        else if(property->propertyName() == "HoverIcon")
        {
            m_buttons[i]->setIconHover(pixmap);
        }
        else if(property->propertyName() == "CheckIcon")
        {
            m_buttons[i]->setIconCheck(pixmap);
        }
    }
}


//
TTKFunctionNavigationBWidgetProperty::TTKFunctionNavigationBWidgetProperty(QWidget *parent)
    : TTKFunctionNavigationWidgetProperty(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(m_item);
    layout->setSpacing(2);
    m_item->setLayout(layout);

    for(int i = 0; i < m_buttons.count(); ++i)
    {
        layout->addWidget(m_buttons[i]);
    }
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObject_cast(TTKFunctionNavigationWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *showIconItem = m_boolManager->addProperty("ShowIcon");
    m_boolManager->setValue(showIconItem, true);
    objectItem->addSubProperty(showIconItem);
    //
    QtProperty *showTriangleItem = m_boolManager->addProperty("ShowTriangle");
    m_boolManager->setValue(showTriangleItem, true);
    objectItem->addSubProperty(showTriangleItem);
    //
    QtProperty *iconSpaceItem = m_intManager->addProperty("IconSpace");
    m_intManager->setMinimum(iconSpaceItem, 0);
    m_intManager->setValue(iconSpaceItem, 10);
    objectItem->addSubProperty(iconSpaceItem);
    //
    QtProperty *iconSizeItem = m_sizeManager->addProperty("IconSize");
    m_sizeManager->setMinimum(iconSizeItem, QSize(0, 0));
    m_sizeManager->setValue(iconSizeItem, QSize(10, 10));
    objectItem->addSubProperty(iconSizeItem);
    //
    QtProperty *normalIconItem = m_colorManager->addProperty("NormalIcon");
    m_colorManager->setValue(normalIconItem, QColor(255, 255, 255));
    objectItem->addSubProperty(normalIconItem);
    //
    QtProperty *hoverIconItem = m_colorManager->addProperty("HoverIcon");
    m_colorManager->setValue(hoverIconItem, QColor(150, 150, 150));
    objectItem->addSubProperty(hoverIconItem);
    //
    QtProperty *checkIconItem = m_colorManager->addProperty("CheckIcon");
    m_colorManager->setValue(checkIconItem, QColor(50, 50, 50));
    objectItem->addSubProperty(checkIconItem);
    //
    QtProperty *paddingLeftItem = m_intManager->addProperty("PaddingLeft");
    m_intManager->setMinimum(paddingLeftItem, 0);
    m_intManager->setValue(paddingLeftItem, 35);
    objectItem->addSubProperty(paddingLeftItem);
    //
    QtProperty *lineSpaceItem = m_intManager->addProperty("LineSpace");
    m_intManager->setMinimum(lineSpaceItem, 0);
    m_intManager->setValue(lineSpaceItem, 0);
    objectItem->addSubProperty(lineSpaceItem);
    //
    QtProperty *lineWidthItem = m_intManager->addProperty("LineWidth");
    m_intManager->setMinimum(lineWidthItem, 0);
    m_intManager->setValue(lineWidthItem, 8);
    objectItem->addSubProperty(lineWidthItem);
    //
    QtProperty *lineColorItem = m_colorManager->addProperty("LineColor");
    m_colorManager->setValue(lineColorItem, QColor(255, 107, 107));
    objectItem->addSubProperty(lineColorItem);
    //
    QtProperty *normalBgColorItem = m_colorManager->addProperty("NormalBgColor");
    m_colorManager->setValue(normalBgColorItem, QColor(0x2D, 0x91, 0x91));
    objectItem->addSubProperty(normalBgColorItem);
    //
    QtProperty *hoverBgColorItem = m_colorManager->addProperty("HoverlBgColor");
    m_colorManager->setValue(hoverBgColorItem, QColor(0x18, 0x72, 0x94));
    objectItem->addSubProperty(hoverBgColorItem);
    //
    QtProperty *checkBgColorItem = m_colorManager->addProperty("CheckBgColor");
    m_colorManager->setValue(checkBgColorItem, QColor(0x14, 0x5C, 0x75));
    objectItem->addSubProperty(checkBgColorItem);
    //
    QtProperty *normalTextColorItem = m_colorManager->addProperty("NormalTextColor");
    m_colorManager->setValue(normalTextColorItem, QColor(0xFF, 0xFF, 0xFF));
    objectItem->addSubProperty(normalTextColorItem);
    //
    QtProperty *hoverTextColorItem = m_colorManager->addProperty("HoverTextColor");
    m_colorManager->setValue(hoverTextColorItem, QColor(0xFF, 0xFF, 0xFF));
    objectItem->addSubProperty(hoverTextColorItem);
    //
    QtProperty *checkTextColorItem = m_colorManager->addProperty("CheckTextColor");
    m_colorManager->setValue(checkTextColorItem, QColor(0xFF, 0xFF, 0xFF));
    objectItem->addSubProperty(checkTextColorItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKFunctionNavigationBWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "ShowIcon")
        {
            m_buttons[i]->setShowIcon(value);
        }
        else if(property->propertyName() == "ShowTriangle")
        {
            m_buttons[i]->setShowTriangle(value);
        }
    }
}

void TTKFunctionNavigationBWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "IconSpace")
        {
            m_buttons[i]->setIconSpace(value);
        }
        else if(property->propertyName() == "PaddingLeft")
        {
            m_buttons[i]->setPaddingLeft(value);
        }
        else if(property->propertyName() == "LineSpace")
        {
            m_buttons[i]->setLineSpace(value);
        }
        else if(property->propertyName() == "LineWidth")
        {
            m_buttons[i]->setLineWidth(value);
        }
    }
}

void TTKFunctionNavigationBWidgetProperty::sizePropertyChanged(QtProperty *property, const QSize &value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "IconSize")
        {
            m_buttons[i]->setIconSize(value);
        }
    }
}

void TTKFunctionNavigationBWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    QPixmap pixmap(1, 1);
    pixmap.fill(value);
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "NormalIcon")
        {
            m_buttons[i]->setIconNormal(pixmap);
        }
        else if(property->propertyName() == "HoverIcon")
        {
            m_buttons[i]->setIconHover(pixmap);
        }
        else if(property->propertyName() == "CheckIcon")
        {
            m_buttons[i]->setIconCheck(pixmap);
        }
        else if(property->propertyName() == "LineColor")
        {
            m_buttons[i]->setLineColor(value);
        }
        else if(property->propertyName() == "NormalBgColor")
        {
            m_buttons[i]->setNormalBgColor(value);
        }
        else if(property->propertyName() == "HoverlBgColor")
        {
            m_buttons[i]->setHoverBgColor(value);
        }
        else if(property->propertyName() == "CheckBgColor")
        {
            m_buttons[i]->setCheckBgColor(value);
        }
        else if(property->propertyName() == "NormalTextColor")
        {
            m_buttons[i]->setNormalTextColor(value);
        }
        else if(property->propertyName() == "HoverTextColor")
        {
            m_buttons[i]->setHoverTextColor(value);
        }
        else if(property->propertyName() == "CheckTextColor")
        {
            m_buttons[i]->setCheckTextColor(value);
        }
    }
}


//
TTKFunctionNavigationCWidgetProperty::TTKFunctionNavigationCWidgetProperty(QWidget *parent)
    : TTKFunctionNavigationWidgetProperty(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(m_item);
    layout->setSpacing(2);
    m_item->setLayout(layout);

    for(int i = 0; i < m_buttons.count(); ++i)
    {
        layout->addWidget(m_buttons[i]);
    }
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObject_cast(TTKFunctionNavigationWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *showIconItem = m_boolManager->addProperty("ShowIcon");
    m_boolManager->setValue(showIconItem, true);
    objectItem->addSubProperty(showIconItem);
    //
    QtProperty *showTriangleItem = m_boolManager->addProperty("ShowTriangle");
    m_boolManager->setValue(showTriangleItem, true);
    objectItem->addSubProperty(showTriangleItem);
    //
    QtProperty *iconSpaceItem = m_intManager->addProperty("IconSpace");
    m_intManager->setMinimum(iconSpaceItem, 0);
    m_intManager->setValue(iconSpaceItem, 10);
    objectItem->addSubProperty(iconSpaceItem);
    //
    QtProperty *iconSizeItem = m_sizeManager->addProperty("IconSize");
    m_sizeManager->setMinimum(iconSizeItem, QSize(0, 0));
    m_sizeManager->setValue(iconSizeItem, QSize(10, 10));
    objectItem->addSubProperty(iconSizeItem);
    //
    QtProperty *normalIconItem = m_colorManager->addProperty("NormalIcon");
    m_colorManager->setValue(normalIconItem, QColor(255, 255, 255));
    objectItem->addSubProperty(normalIconItem);
    //
    QtProperty *hoverIconItem = m_colorManager->addProperty("HoverIcon");
    m_colorManager->setValue(hoverIconItem, QColor(150, 150, 150));
    objectItem->addSubProperty(hoverIconItem);
    //
    QtProperty *checkIconItem = m_colorManager->addProperty("CheckIcon");
    m_colorManager->setValue(checkIconItem, QColor(50, 50, 50));
    objectItem->addSubProperty(checkIconItem);
    //
    QtProperty *paddingLeftItem = m_intManager->addProperty("PaddingLeft");
    m_intManager->setMinimum(paddingLeftItem, 0);
    m_intManager->setValue(paddingLeftItem, 35);
    objectItem->addSubProperty(paddingLeftItem);
    //
    QtProperty *lineSpaceItem = m_intManager->addProperty("LineSpace");
    m_intManager->setMinimum(lineSpaceItem, 0);
    m_intManager->setValue(lineSpaceItem, 0);
    objectItem->addSubProperty(lineSpaceItem);
    //
    QtProperty *lineWidthItem = m_intManager->addProperty("LineWidth");
    m_intManager->setMinimum(lineWidthItem, 0);
    m_intManager->setValue(lineWidthItem, 8);
    objectItem->addSubProperty(lineWidthItem);
    //
    QtProperty *lineColorItem = m_colorManager->addProperty("LineColor");
    m_colorManager->setValue(lineColorItem, QColor(0x02, 0x9F, 0xEA));
    objectItem->addSubProperty(lineColorItem);
    //
    QtProperty *textAlignItem = m_enumManager->addProperty("TextAlign");
    QStringList textAlignNames;
    textAlignNames << "TextAlignLeft" << "TextAlignRight" << "TextAlignTop" << "TextAlignBottom" << "TextAlignCenter";
    m_enumManager->setEnumNames(textAlignItem, textAlignNames);
    m_enumManager->setValue(textAlignItem, 0);
    objectItem->addSubProperty(textAlignItem);
    //
    QtProperty *trianglePositionItem = m_enumManager->addProperty("TrianglePosition");
    QStringList trianglePositionNames;
    trianglePositionNames << "TrianglePositionLeft" << "TrianglePositionRight" << "TrianglePositionTop" << "TrianglePositionBottom";
    m_enumManager->setEnumNames(trianglePositionItem, trianglePositionNames);
    m_enumManager->setValue(trianglePositionItem, TTKStatic_cast(int, TTKFunctionNavigationWidget::TrianglePosition::Left));
    objectItem->addSubProperty(trianglePositionItem);
    //
    QtProperty *linePositionItem = m_enumManager->addProperty("LinePosition");
    QStringList linePositionNames;
    linePositionNames << "LinePositionLeft" << "LinePositionRight" << "LinePositionTop" << "LinePositionBottom";
    m_enumManager->setEnumNames(linePositionItem, linePositionNames);
    m_enumManager->setValue(linePositionItem, TTKStatic_cast(int, TTKFunctionNavigationWidget::LinePosition::Right));
    objectItem->addSubProperty(linePositionItem);
    //
    QtProperty *normalBgColorItem = m_colorManager->addProperty("NormalBgColor");
    m_colorManager->setValue(normalBgColorItem, QColor(0x29, 0x2F, 0x38));
    objectItem->addSubProperty(normalBgColorItem);
    //
    QtProperty *hoverBgColorItem = m_colorManager->addProperty("HoverlBgColor");
    m_colorManager->setValue(hoverBgColorItem, QColor(0x1D, 0x20, 0x25));
    objectItem->addSubProperty(hoverBgColorItem);
    //
    QtProperty *checkBgColorItem = m_colorManager->addProperty("CheckBgColor");
    m_colorManager->setValue(checkBgColorItem, QColor(0x1D, 0x20, 0x25));
    objectItem->addSubProperty(checkBgColorItem);
    //
    QtProperty *normalTextColorItem = m_colorManager->addProperty("NormalTextColor");
    m_colorManager->setValue(normalTextColorItem, QColor(0x54, 0x62, 0x6F));
    objectItem->addSubProperty(normalTextColorItem);
    //
    QtProperty *hoverTextColorItem = m_colorManager->addProperty("HoverTextColor");
    m_colorManager->setValue(hoverTextColorItem, QColor(0xFD, 0xFD, 0xFD));
    objectItem->addSubProperty(hoverTextColorItem);
    //
    QtProperty *checkTextColorItem = m_colorManager->addProperty("CheckTextColor");
    m_colorManager->setValue(checkTextColorItem, QColor(0xFD, 0xFD, 0xFD));
    objectItem->addSubProperty(checkTextColorItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKFunctionNavigationCWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "ShowIcon")
        {
            m_buttons[i]->setShowIcon(value);
        }
        else if(property->propertyName() == "ShowTriangle")
        {
            m_buttons[i]->setShowTriangle(value);
        }
    }
}

void TTKFunctionNavigationCWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "IconSpace")
        {
            m_buttons[i]->setIconSpace(value);
        }
        else if(property->propertyName() == "PaddingLeft")
        {
            m_buttons[i]->setPaddingLeft(value);
        }
        else if(property->propertyName() == "LineSpace")
        {
            m_buttons[i]->setLineSpace(value);
        }
        else if(property->propertyName() == "LineWidth")
        {
            m_buttons[i]->setLineWidth(value);
        }
    }
}

void TTKFunctionNavigationCWidgetProperty::sizePropertyChanged(QtProperty *property, const QSize &value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "IconSize")
        {
            m_buttons[i]->setIconSize(value);
        }
    }
}

void TTKFunctionNavigationCWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "TextAlign")
        {
            Qt::Alignment style = Qt::AlignRight;
            switch(value)
            {
                case 0: style = Qt::AlignLeft; break;
                case 1: style = Qt::AlignRight; break;
                case 2: style = Qt::AlignTop; break;
                case 3: style = Qt::AlignBottom; break;
                case 4: style = Qt::AlignHCenter; break;
            }
            m_buttons[i]->setTextAlign(style);
        }
        else if(property->propertyName() == "TrianglePosition")
        {
            m_buttons[i]->setTrianglePosition(TTKStatic_cast(TTKFunctionNavigationWidget::TrianglePosition, value));
        }
        else if(property->propertyName() == "LinePosition")
        {
            m_buttons[i]->setLinePosition(TTKStatic_cast(TTKFunctionNavigationWidget::LinePosition, value));
        }
    }
}

void TTKFunctionNavigationCWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    QPixmap pixmap(1, 1);
    pixmap.fill(value);
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "NormalIcon")
        {
            m_buttons[i]->setIconNormal(pixmap);
        }
        else if(property->propertyName() == "HoverIcon")
        {
            m_buttons[i]->setIconHover(pixmap);
        }
        else if(property->propertyName() == "CheckIcon")
        {
            m_buttons[i]->setIconCheck(pixmap);
        }
        else if(property->propertyName() == "LineColor")
        {
            m_buttons[i]->setLineColor(value);
        }
        else if(property->propertyName() == "NormalBgColor")
        {
            m_buttons[i]->setNormalBgColor(value);
        }
        else if(property->propertyName() == "HoverlBgColor")
        {
            m_buttons[i]->setHoverBgColor(value);
        }
        else if(property->propertyName() == "CheckBgColor")
        {
            m_buttons[i]->setCheckBgColor(value);
        }
        else if(property->propertyName() == "NormalTextColor")
        {
            m_buttons[i]->setNormalTextColor(value);
        }
        else if(property->propertyName() == "HoverTextColor")
        {
            m_buttons[i]->setHoverTextColor(value);
        }
        else if(property->propertyName() == "CheckTextColor")
        {
            m_buttons[i]->setCheckTextColor(value);
        }
    }
}


//
TTKFunctionNavigationDWidgetProperty::TTKFunctionNavigationDWidgetProperty(QWidget *parent)
    : TTKFunctionNavigationWidgetProperty(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(m_item);
    layout->setSpacing(2);
    m_item->setLayout(layout);

    for(int i = 0; i < m_buttons.count(); ++i)
    {
        layout->addWidget(m_buttons[i]);
    }
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObject_cast(TTKFunctionNavigationWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *showIconItem = m_boolManager->addProperty("ShowIcon");
    m_boolManager->setValue(showIconItem, true);
    objectItem->addSubProperty(showIconItem);
    //
    QtProperty *showTriangleItem = m_boolManager->addProperty("ShowTriangle");
    m_boolManager->setValue(showTriangleItem, true);
    objectItem->addSubProperty(showTriangleItem);
    //
    QtProperty *iconSpaceItem = m_intManager->addProperty("IconSpace");
    m_intManager->setMinimum(iconSpaceItem, 0);
    m_intManager->setValue(iconSpaceItem, 0);
    objectItem->addSubProperty(iconSpaceItem);
    //
    QtProperty *iconSizeItem = m_sizeManager->addProperty("IconSize");
    m_sizeManager->setMinimum(iconSizeItem, QSize(0, 0));
    m_sizeManager->setValue(iconSizeItem, QSize(15, 15));
    objectItem->addSubProperty(iconSizeItem);
    //
    QtProperty *normalIconItem = m_colorManager->addProperty("NormalIcon");
    m_colorManager->setValue(normalIconItem, QColor(255, 255, 255));
    objectItem->addSubProperty(normalIconItem);
    //
    QtProperty *hoverIconItem = m_colorManager->addProperty("HoverIcon");
    m_colorManager->setValue(hoverIconItem, QColor(150, 150, 150));
    objectItem->addSubProperty(hoverIconItem);
    //
    QtProperty *checkIconItem = m_colorManager->addProperty("CheckIcon");
    m_colorManager->setValue(checkIconItem, QColor(50, 50, 50));
    objectItem->addSubProperty(checkIconItem);
    //
    QtProperty *paddingRightItem = m_intManager->addProperty("PaddingRight");
    m_intManager->setMinimum(paddingRightItem, 0);
    m_intManager->setValue(paddingRightItem, 25);
    objectItem->addSubProperty(paddingRightItem);
    //
    QtProperty *lineSpaceItem = m_intManager->addProperty("LineSpace");
    m_intManager->setMinimum(lineSpaceItem, 0);
    m_intManager->setValue(lineSpaceItem, 10);
    objectItem->addSubProperty(lineSpaceItem);
    //
    QtProperty *lineWidthItem = m_intManager->addProperty("LineWidth");
    m_intManager->setMinimum(lineWidthItem, 0);
    m_intManager->setValue(lineWidthItem, 10);
    objectItem->addSubProperty(lineWidthItem);
    //
    QtProperty *textAlignItem = m_enumManager->addProperty("TextAlign");
    QStringList textAlignNames;
    textAlignNames << "TextAlignLeft" << "TextAlignRight" << "TextAlignTop" << "TextAlignBottom" << "TextAlignCenter";
    m_enumManager->setEnumNames(textAlignItem, textAlignNames);
    m_enumManager->setValue(textAlignItem, 1);
    objectItem->addSubProperty(textAlignItem);
    //
    QtProperty *trianglePositionItem = m_enumManager->addProperty("TrianglePosition");
    QStringList trianglePositionNames;
    trianglePositionNames << "TrianglePositionLeft" << "TrianglePositionRight" << "TrianglePositionTop" << "TrianglePositionBottom";
    m_enumManager->setEnumNames(trianglePositionItem, trianglePositionNames);
    m_enumManager->setValue(trianglePositionItem, TTKStatic_cast(int, TTKFunctionNavigationWidget::TrianglePosition::Left));
    objectItem->addSubProperty(trianglePositionItem);
    //
    QtProperty *linePositionItem = m_enumManager->addProperty("LinePosition");
    QStringList linePositionNames;
    linePositionNames << "LinePositionLeft" << "LinePositionRight" << "LinePositionTop" << "LinePositionBottom";
    m_enumManager->setEnumNames(linePositionItem, linePositionNames);
    m_enumManager->setValue(linePositionItem, TTKStatic_cast(int, TTKFunctionNavigationWidget::LinePosition::Right));
    objectItem->addSubProperty(linePositionItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKFunctionNavigationDWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "ShowIcon")
        {
            m_buttons[i]->setShowIcon(value);
        }
        else if(property->propertyName() == "ShowTriangle")
        {
            m_buttons[i]->setShowTriangle(value);
        }
    }
}

void TTKFunctionNavigationDWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "IconSpace")
        {
            m_buttons[i]->setIconSpace(value);
        }
        else if(property->propertyName() == "PaddingRight")
        {
            m_buttons[i]->setPaddingRight(value);
        }
        else if(property->propertyName() == "LineSpace")
        {
            m_buttons[i]->setLineSpace(value);
        }
        else if(property->propertyName() == "LineWidth")
        {
            m_buttons[i]->setLineWidth(value);
        }
    }
}

void TTKFunctionNavigationDWidgetProperty::sizePropertyChanged(QtProperty *property, const QSize &value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "IconSize")
        {
            m_buttons[i]->setIconSize(value);
        }
    }
}

void TTKFunctionNavigationDWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "TextAlign")
        {
            Qt::Alignment style = Qt::AlignRight;
            switch(value)
            {
                case 0: style = Qt::AlignLeft; break;
                case 1: style = Qt::AlignRight; break;
                case 2: style = Qt::AlignTop; break;
                case 3: style = Qt::AlignBottom; break;
                case 4: style = Qt::AlignHCenter; break;
            }
            m_buttons[i]->setTextAlign(style);
        }
        else if(property->propertyName() == "TrianglePosition")
        {
            m_buttons[i]->setTrianglePosition(TTKStatic_cast(TTKFunctionNavigationWidget::TrianglePosition, value));
        }
        else if(property->propertyName() == "LinePosition")
        {
            m_buttons[i]->setLinePosition(TTKStatic_cast(TTKFunctionNavigationWidget::LinePosition, value));
        }
    }
}

void TTKFunctionNavigationDWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    QPixmap pixmap(1, 1);
    pixmap.fill(value);
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "NormalIcon")
        {
            m_buttons[i]->setIconNormal(pixmap);
        }
        else if(property->propertyName() == "HoverIcon")
        {
            m_buttons[i]->setIconHover(pixmap);
        }
        else if(property->propertyName() == "CheckIcon")
        {
            m_buttons[i]->setIconCheck(pixmap);
        }
    }
}


//
TTKFunctionNavigationEWidgetProperty::TTKFunctionNavigationEWidgetProperty(QWidget *parent)
    : TTKFunctionNavigationWidgetProperty(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(m_item);
    layout->setSpacing(0);
    m_item->setLayout(layout);

    QFont font;
    font.setPixelSize(15);
    font.setBold(true);

    for(int i = 0; i < m_buttons.count(); ++i)
    {
        m_buttons[i]->setFont(font);
        m_buttons[i]->setShowLine(false);
        layout->addWidget(m_buttons[i]);
    }
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObject_cast(TTKFunctionNavigationWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *showIconItem = m_boolManager->addProperty("ShowIcon");
    m_boolManager->setValue(showIconItem, true);
    objectItem->addSubProperty(showIconItem);
    //
    QtProperty *showLineItem = m_boolManager->addProperty("ShowLine");
    m_boolManager->setValue(showLineItem, false);
    objectItem->addSubProperty(showLineItem);
    //
    QtProperty *iconSpaceItem = m_intManager->addProperty("IconSpace");
    m_intManager->setMinimum(iconSpaceItem, 0);
    m_intManager->setValue(iconSpaceItem, 15);
    objectItem->addSubProperty(iconSpaceItem);
    //
    QtProperty *iconSizeItem = m_sizeManager->addProperty("IconSize");
    m_sizeManager->setMinimum(iconSizeItem, QSize(0, 0));
    m_sizeManager->setValue(iconSizeItem, QSize(15, 15));
    objectItem->addSubProperty(iconSizeItem);
    //
    QtProperty *normalIconItem = m_colorManager->addProperty("NormalIcon");
    m_colorManager->setValue(normalIconItem, QColor(255, 255, 255));
    objectItem->addSubProperty(normalIconItem);
    //
    QtProperty *hoverIconItem = m_colorManager->addProperty("HoverIcon");
    m_colorManager->setValue(hoverIconItem, QColor(150, 150, 150));
    objectItem->addSubProperty(hoverIconItem);
    //
    QtProperty *checkIconItem = m_colorManager->addProperty("CheckIcon");
    m_colorManager->setValue(checkIconItem, QColor(50, 50, 50));
    objectItem->addSubProperty(checkIconItem);
    //
    QtProperty *paddingLeftItem = m_intManager->addProperty("PaddingLeft");
    m_intManager->setMinimum(paddingLeftItem, 0);
    m_intManager->setValue(paddingLeftItem, 20);
    objectItem->addSubProperty(paddingLeftItem);
    //
    QtProperty *textAlignItem = m_enumManager->addProperty("TextAlign");
    QStringList textAlignNames;
    textAlignNames << "TextAlignLeft" << "TextAlignRight" << "TextAlignTop" << "TextAlignBottom" << "TextAlignCenter";
    m_enumManager->setEnumNames(textAlignItem, textAlignNames);
    m_enumManager->setValue(textAlignItem, 4);
    objectItem->addSubProperty(textAlignItem);
    //
    QtProperty *linePositionItem = m_enumManager->addProperty("LinePosition");
    QStringList linePositionNames;
    linePositionNames << "LinePositionLeft" << "LinePositionRight" << "LinePositionTop" << "LinePositionBottom";
    m_enumManager->setEnumNames(linePositionItem, linePositionNames);
    m_enumManager->setValue(linePositionItem, TTKStatic_cast(int, TTKFunctionNavigationWidget::LinePosition::Top));
    objectItem->addSubProperty(linePositionItem);
    //
    QtProperty *normalBgColorItem = m_colorManager->addProperty("NormalBgColor");
    m_colorManager->setValue(normalBgColorItem, QColor(0x29, 0x29, 0x29));
    objectItem->addSubProperty(normalBgColorItem);
    //
    QtProperty *hoverBgColorItem = m_colorManager->addProperty("HoverlBgColor");
    m_colorManager->setValue(hoverBgColorItem, QColor(0x06, 0x40, 0x77));
    objectItem->addSubProperty(hoverBgColorItem);
    //
    QtProperty *checkBgColorItem = m_colorManager->addProperty("CheckBgColor");
    m_colorManager->setValue(checkBgColorItem, QColor(0x10, 0x68, 0x9A));
    objectItem->addSubProperty(checkBgColorItem);
    //
    QtProperty *normalTextColorItem = m_colorManager->addProperty("NormalTextColor");
    m_colorManager->setValue(normalTextColorItem, QColor(0xFF, 0xFF, 0xFF));
    objectItem->addSubProperty(normalTextColorItem);
    //
    QtProperty *hoverTextColorItem = m_colorManager->addProperty("HoverTextColor");
    m_colorManager->setValue(hoverTextColorItem, QColor(0xFF, 0xFF, 0x00));
    objectItem->addSubProperty(hoverTextColorItem);
    //
    QtProperty *checkTextColorItem = m_colorManager->addProperty("CheckTextColor");
    m_colorManager->setValue(checkTextColorItem, QColor(0xFF, 0xFF, 0xFF));
    objectItem->addSubProperty(checkTextColorItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKFunctionNavigationEWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "ShowIcon")
        {
            m_buttons[i]->setShowIcon(value);
        }
        else if(property->propertyName() == "ShowLine")
        {
            m_buttons[i]->setShowLine(value);
        }
    }
}

void TTKFunctionNavigationEWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "IconSpace")
        {
            m_buttons[i]->setIconSpace(value);
        }
        else if(property->propertyName() == "PaddingLeft")
        {
            m_buttons[i]->setPaddingLeft(value);
        }
    }
}

void TTKFunctionNavigationEWidgetProperty::sizePropertyChanged(QtProperty *property, const QSize &value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "IconSize")
        {
            m_buttons[i]->setIconSize(value);
        }
    }
}

void TTKFunctionNavigationEWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "TextAlign")
        {
            Qt::Alignment style = Qt::AlignRight;
            switch(value)
            {
                case 0: style = Qt::AlignLeft; break;
                case 1: style = Qt::AlignRight; break;
                case 2: style = Qt::AlignTop; break;
                case 3: style = Qt::AlignBottom; break;
                case 4: style = Qt::AlignHCenter; break;
            }
            m_buttons[i]->setTextAlign(style);
        }
        else if(property->propertyName() == "LinePosition")
        {
            m_buttons[i]->setLinePosition(TTKStatic_cast(TTKFunctionNavigationWidget::LinePosition, value));
        }
    }
}

void TTKFunctionNavigationEWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    QPixmap pixmap(1, 1);
    pixmap.fill(value);
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "NormalIcon")
        {
            m_buttons[i]->setIconNormal(pixmap);
        }
        else if(property->propertyName() == "HoverIcon")
        {
            m_buttons[i]->setIconHover(pixmap);
        }
        else if(property->propertyName() == "CheckIcon")
        {
            m_buttons[i]->setIconCheck(pixmap);
        }
        else if(property->propertyName() == "NormalBgColor")
        {
            m_buttons[i]->setNormalBgColor(value);
        }
        else if(property->propertyName() == "HoverlBgColor")
        {
            m_buttons[i]->setHoverBgColor(value);
        }
        else if(property->propertyName() == "CheckBgColor")
        {
            m_buttons[i]->setCheckBgColor(value);
        }
        else if(property->propertyName() == "NormalTextColor")
        {
            m_buttons[i]->setNormalTextColor(value);
        }
        else if(property->propertyName() == "HoverTextColor")
        {
            m_buttons[i]->setHoverTextColor(value);
        }
        else if(property->propertyName() == "CheckTextColor")
        {
            m_buttons[i]->setCheckTextColor(value);
        }
    }
}


//
TTKFunctionNavigationFWidgetProperty::TTKFunctionNavigationFWidgetProperty(QWidget *parent)
    : TTKFunctionNavigationWidgetProperty(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(m_item);
    layout->setSpacing(0);
    m_item->setLayout(layout);

    QFont font;
    font.setPixelSize(15);
    font.setBold(true);

    for(int i = 0; i < m_buttons.count(); ++i)
    {
        m_buttons[i]->setFont(font);
        m_buttons[i]->setShowLine(false);
        layout->addWidget(m_buttons[i]);
    }
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObject_cast(TTKFunctionNavigationWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *showIconItem = m_boolManager->addProperty("ShowIcon");
    m_boolManager->setValue(showIconItem, true);
    objectItem->addSubProperty(showIconItem);
    //
    QtProperty *showLineItem = m_boolManager->addProperty("ShowLine");
    m_boolManager->setValue(showLineItem, false);
    objectItem->addSubProperty(showLineItem);
    //
    QtProperty *iconSpaceItem = m_intManager->addProperty("IconSpace");
    m_intManager->setMinimum(iconSpaceItem, 0);
    m_intManager->setValue(iconSpaceItem, 15);
    objectItem->addSubProperty(iconSpaceItem);
    //
    QtProperty *iconSizeItem = m_sizeManager->addProperty("IconSize");
    m_sizeManager->setMinimum(iconSizeItem, QSize(0, 0));
    m_sizeManager->setValue(iconSizeItem, QSize(15, 15));
    objectItem->addSubProperty(iconSizeItem);
    //
    QtProperty *normalIconItem = m_colorManager->addProperty("NormalIcon");
    m_colorManager->setValue(normalIconItem, QColor(255, 255, 255));
    objectItem->addSubProperty(normalIconItem);
    //
    QtProperty *hoverIconItem = m_colorManager->addProperty("HoverIcon");
    m_colorManager->setValue(hoverIconItem, QColor(150, 150, 150));
    objectItem->addSubProperty(hoverIconItem);
    //
    QtProperty *checkIconItem = m_colorManager->addProperty("CheckIcon");
    m_colorManager->setValue(checkIconItem, QColor(50, 50, 50));
    objectItem->addSubProperty(checkIconItem);
    //
    QtProperty *paddingLeftItem = m_intManager->addProperty("PaddingLeft");
    m_intManager->setMinimum(paddingLeftItem, 0);
    m_intManager->setValue(paddingLeftItem, 20);
    objectItem->addSubProperty(paddingLeftItem);
    //
    QtProperty *textAlignItem = m_enumManager->addProperty("TextAlign");
    QStringList textAlignNames;
    textAlignNames << "TextAlignLeft" << "TextAlignRight" << "TextAlignTop" << "TextAlignBottom" << "TextAlignCenter";
    m_enumManager->setEnumNames(textAlignItem, textAlignNames);
    m_enumManager->setValue(textAlignItem, 4);
    objectItem->addSubProperty(textAlignItem);
    //
    QtProperty *linePositionItem = m_enumManager->addProperty("LinePosition");
    QStringList linePositionNames;
    linePositionNames << "LinePositionLeft" << "LinePositionRight" << "LinePositionTop" << "LinePositionBottom";
    m_enumManager->setEnumNames(linePositionItem, linePositionNames);
    m_enumManager->setValue(linePositionItem, TTKStatic_cast(int, TTKFunctionNavigationWidget::LinePosition::Top));
    objectItem->addSubProperty(linePositionItem);
    //
    QtProperty *normalBgColorItem = m_colorManager->addProperty("NormalBgColor");
    m_colorManager->setValue(normalBgColorItem, QColor(0xE6, 0x39, 0x3D));
    objectItem->addSubProperty(normalBgColorItem);
    //
    QtProperty *hoverBgColorItem = m_colorManager->addProperty("HoverlBgColor");
    m_colorManager->setValue(hoverBgColorItem, QColor(0xEE, 0x00, 0x00));
    objectItem->addSubProperty(hoverBgColorItem);
    //
    QtProperty *checkBgColorItem = m_colorManager->addProperty("CheckBgColor");
    m_colorManager->setValue(checkBgColorItem, QColor(0xA4, 0x00, 0x01));
    objectItem->addSubProperty(checkBgColorItem);
    //
    QtProperty *normalTextColorItem = m_colorManager->addProperty("NormalTextColor");
    m_colorManager->setValue(normalTextColorItem, QColor(0xFF, 0xFF, 0xFF));
    objectItem->addSubProperty(normalTextColorItem);
    //
    QtProperty *hoverTextColorItem = m_colorManager->addProperty("HoverTextColor");
    m_colorManager->setValue(hoverTextColorItem, QColor(0xFF, 0xFF, 0xFF));
    objectItem->addSubProperty(hoverTextColorItem);
    //
    QtProperty *checkTextColorItem = m_colorManager->addProperty("CheckTextColor");
    m_colorManager->setValue(checkTextColorItem, QColor(0xFF, 0xFF, 0xFF));
    objectItem->addSubProperty(checkTextColorItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKFunctionNavigationFWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "ShowIcon")
        {
            m_buttons[i]->setShowIcon(value);
        }
        else if(property->propertyName() == "ShowLine")
        {
            m_buttons[i]->setShowLine(value);
        }
    }
}

void TTKFunctionNavigationFWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "IconSpace")
        {
            m_buttons[i]->setIconSpace(value);
        }
        else if(property->propertyName() == "PaddingLeft")
        {
            m_buttons[i]->setPaddingLeft(value);
        }
    }
}

void TTKFunctionNavigationFWidgetProperty::sizePropertyChanged(QtProperty *property, const QSize &value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "IconSize")
        {
            m_buttons[i]->setIconSize(value);
        }
    }
}

void TTKFunctionNavigationFWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "TextAlign")
        {
            Qt::Alignment style = Qt::AlignRight;
            switch(value)
            {
                case 0: style = Qt::AlignLeft; break;
                case 1: style = Qt::AlignRight; break;
                case 2: style = Qt::AlignTop; break;
                case 3: style = Qt::AlignBottom; break;
                case 4: style = Qt::AlignHCenter; break;
            }
            m_buttons[i]->setTextAlign(style);
        }
        else if(property->propertyName() == "LinePosition")
        {
            m_buttons[i]->setLinePosition(TTKStatic_cast(TTKFunctionNavigationWidget::LinePosition, value));
        }
    }
}

void TTKFunctionNavigationFWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    QPixmap pixmap(1, 1);
    pixmap.fill(value);
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "NormalIcon")
        {
            m_buttons[i]->setIconNormal(pixmap);
        }
        else if(property->propertyName() == "HoverIcon")
        {
            m_buttons[i]->setIconHover(pixmap);
        }
        else if(property->propertyName() == "CheckIcon")
        {
            m_buttons[i]->setIconCheck(pixmap);
        }
        else if(property->propertyName() == "NormalBgColor")
        {
            m_buttons[i]->setNormalBgColor(value);
        }
        else if(property->propertyName() == "HoverlBgColor")
        {
            m_buttons[i]->setHoverBgColor(value);
        }
        else if(property->propertyName() == "CheckBgColor")
        {
            m_buttons[i]->setCheckBgColor(value);
        }
        else if(property->propertyName() == "NormalTextColor")
        {
            m_buttons[i]->setNormalTextColor(value);
        }
        else if(property->propertyName() == "HoverTextColor")
        {
            m_buttons[i]->setHoverTextColor(value);
        }
        else if(property->propertyName() == "CheckTextColor")
        {
            m_buttons[i]->setCheckTextColor(value);
        }
    }
}


//
TTKFunctionNavigationGWidgetProperty::TTKFunctionNavigationGWidgetProperty(QWidget *parent)
    : TTKFunctionNavigationWidgetProperty(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(m_item);
    layout->setSpacing(0);
    m_item->setLayout(layout);

    QFont font;
    font.setPixelSize(15);
    font.setBold(true);

    for(int i = 0; i < m_buttons.count(); ++i)
    {
        m_buttons[i]->setFont(font);
        layout->addWidget(m_buttons[i]);
    }
    //
    m_normal = QLinearGradient(0, 0, 0, 30);
    m_hover = QLinearGradient(0, 0, 0, 30);
    m_check = QLinearGradient(0, 0, 0, 30);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObject_cast(TTKFunctionNavigationWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *showTriangleItem = m_boolManager->addProperty("ShowTriangle");
    m_boolManager->setValue(showTriangleItem, true);
    objectItem->addSubProperty(showTriangleItem);
    //
    QtProperty *normalIconItem = m_colorManager->addProperty("NormalIcon");
    m_colorManager->setValue(normalIconItem, QColor(255, 255, 255));
    objectItem->addSubProperty(normalIconItem);
    //
    QtProperty *hoverIconItem = m_colorManager->addProperty("HoverIcon");
    m_colorManager->setValue(hoverIconItem, QColor(150, 150, 150));
    objectItem->addSubProperty(hoverIconItem);
    //
    QtProperty *checkIconItem = m_colorManager->addProperty("CheckIcon");
    m_colorManager->setValue(checkIconItem, QColor(50, 50, 50));
    objectItem->addSubProperty(checkIconItem);
    //
    QtProperty *paddingLeftItem = m_intManager->addProperty("PaddingLeft");
    m_intManager->setMinimum(paddingLeftItem, 0);
    m_intManager->setValue(paddingLeftItem, 0);
    objectItem->addSubProperty(paddingLeftItem);
    //
    QtProperty *lineSpaceItem = m_intManager->addProperty("LineSpace");
    m_intManager->setMinimum(lineSpaceItem, 0);
    m_intManager->setValue(lineSpaceItem, 0);
    objectItem->addSubProperty(lineSpaceItem);
    //
    QtProperty *textAlignItem = m_enumManager->addProperty("TextAlign");
    QStringList textAlignNames;
    textAlignNames << "TextAlignLeft" << "TextAlignRight" << "TextAlignTop" << "TextAlignBottom" << "TextAlignCenter";
    m_enumManager->setEnumNames(textAlignItem, textAlignNames);
    m_enumManager->setValue(textAlignItem, 4);
    objectItem->addSubProperty(textAlignItem);
    //
    QtProperty *trianglePositionItem = m_enumManager->addProperty("TrianglePosition");
    QStringList trianglePositionNames;
    trianglePositionNames << "TrianglePositionLeft" << "TrianglePositionRight" << "TrianglePositionTop" << "TrianglePositionBottom";
    m_enumManager->setEnumNames(trianglePositionItem, trianglePositionNames);
    m_enumManager->setValue(trianglePositionItem, TTKStatic_cast(int, TTKFunctionNavigationWidget::TrianglePosition::Bottom));
    objectItem->addSubProperty(trianglePositionItem);
    //
    QtProperty *linePositionItem = m_enumManager->addProperty("LinePosition");
    QStringList linePositionNames;
    linePositionNames << "LinePositionLeft" << "LinePositionRight" << "LinePositionTop" << "LinePositionBottom";
    m_enumManager->setEnumNames(linePositionItem, linePositionNames);
    m_enumManager->setValue(linePositionItem, TTKStatic_cast(int, TTKFunctionNavigationWidget::LinePosition::Top));
    objectItem->addSubProperty(linePositionItem);
    //
    QtProperty *normalBgBrushRItem = m_colorManager->addProperty("NormalBgBrushR");
    m_colorManager->setValue(normalBgBrushRItem, QColor(0x39, 0x85, 0xBF));
    objectItem->addSubProperty(normalBgBrushRItem);
    //
    QtProperty *normalBgBrushGItem = m_colorManager->addProperty("NormalBgBrushG");
    m_colorManager->setValue(normalBgBrushGItem, QColor(0x29, 0x72, 0xA9));
    objectItem->addSubProperty(normalBgBrushGItem);
    //
    QtProperty *normalBgBrushBItem = m_colorManager->addProperty("NormalBgBrushB");
    m_colorManager->setValue(normalBgBrushBItem, QColor(0x1C, 0x64, 0x96));
    objectItem->addSubProperty(normalBgBrushBItem);
    //
    QtProperty *hoverBgBrushRItem = m_colorManager->addProperty("HoverlBgBrushR");
    m_colorManager->setValue(hoverBgBrushRItem, QColor(0x48, 0x97, 0xD1));
    objectItem->addSubProperty(hoverBgBrushRItem);
    //
    QtProperty *hoverBgBrushGItem = m_colorManager->addProperty("HoverlBgBrushG");
    m_colorManager->setValue(hoverBgBrushGItem, QColor(0x32, 0x83, 0xBC));
    objectItem->addSubProperty(hoverBgBrushGItem);
    //
    QtProperty *hoverBgBrushBItem = m_colorManager->addProperty("HoverlBgBrushB");
    m_colorManager->setValue(hoverBgBrushBItem, QColor(0x30, 0x88, 0xC3));
    objectItem->addSubProperty(hoverBgBrushBItem);
    //
    QtProperty *checkBgBrushRItem = m_colorManager->addProperty("CheckBgBrushR");
    m_colorManager->setValue(checkBgBrushRItem, QColor(0x48, 0x97, 0xD1));
    objectItem->addSubProperty(checkBgBrushRItem);
    //
    QtProperty *checkBgBrushGItem = m_colorManager->addProperty("CheckBgBrushG");
    m_colorManager->setValue(checkBgBrushGItem, QColor(0x32, 0x83, 0xBC));
    objectItem->addSubProperty(checkBgBrushGItem);
    //
    QtProperty *checkBgBrushBItem = m_colorManager->addProperty("CheckBgBrushB");
    m_colorManager->setValue(checkBgBrushBItem, QColor(0x30, 0x88, 0xC3));
    objectItem->addSubProperty(checkBgBrushBItem);
    //
    QtProperty *normalTextColorItem = m_colorManager->addProperty("NormalTextColor");
    m_colorManager->setValue(normalTextColorItem, QColor(0xFF, 0xFF, 0xFF));
    objectItem->addSubProperty(normalTextColorItem);
    //
    QtProperty *hoverTextColorItem = m_colorManager->addProperty("HoverTextColor");
    m_colorManager->setValue(hoverTextColorItem, QColor(0xFF, 0xFF, 0xFF));
    objectItem->addSubProperty(hoverTextColorItem);
    //
    QtProperty *checkTextColorItem = m_colorManager->addProperty("CheckTextColor");
    m_colorManager->setValue(checkTextColorItem, QColor(0xFF, 0xFF, 0xFF));
    objectItem->addSubProperty(checkTextColorItem);
    //
    m_browser->addProperty(objectItem);
}

void TTKFunctionNavigationGWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "ShowTriangle")
        {
            m_buttons[i]->setShowTriangle(value);
        }
    }
}

void TTKFunctionNavigationGWidgetProperty::intPropertyChanged(QtProperty *property, int value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "PaddingLeft")
        {
            m_buttons[i]->setPaddingLeft(value);
        }
        else if(property->propertyName() == "LineSpace")
        {
            m_buttons[i]->setLineSpace(value);
        }
    }
}

void TTKFunctionNavigationGWidgetProperty::enumPropertyChanged(QtProperty *property, int value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "TextAlign")
        {
            Qt::Alignment style = Qt::AlignRight;
            switch(value)
            {
                case 0: style = Qt::AlignLeft; break;
                case 1: style = Qt::AlignRight; break;
                case 2: style = Qt::AlignTop; break;
                case 3: style = Qt::AlignBottom; break;
                case 4: style = Qt::AlignHCenter; break;
            }
            m_buttons[i]->setTextAlign(style);
        }
        else if(property->propertyName() == "TrianglePosition")
        {
            m_buttons[i]->setTrianglePosition(TTKStatic_cast(TTKFunctionNavigationWidget::TrianglePosition, value));
        }
        else if(property->propertyName() == "LinePosition")
        {
            m_buttons[i]->setLinePosition(TTKStatic_cast(TTKFunctionNavigationWidget::LinePosition, value));
        }
    }
}

void TTKFunctionNavigationGWidgetProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    for(int i = 0; i < m_buttons.count(); ++i)
    {
        if(property->propertyName() == "NormalBgBrushR")
        {
            m_normal.setColorAt(0.0, value);
            m_buttons[i]->setNormalBgBrush(m_normal);
        }
        else if(property->propertyName() == "NormalBgBrushG")
        {
            m_normal.setColorAt(0.5, value);
            m_buttons[i]->setNormalBgBrush(m_normal);
        }
        else if(property->propertyName() == "NormalBgBrushB")
        {
            m_normal.setColorAt(1.0, value);
            m_buttons[i]->setNormalBgBrush(m_normal);
        }
        else if(property->propertyName() == "HoverlBgBrushR")
        {
            m_hover.setColorAt(0.0, value);
            m_buttons[i]->setHoverBgBrush(m_hover);
        }
        else if(property->propertyName() == "HoverlBgBrushG")
        {
            m_hover.setColorAt(0.5, value);
            m_buttons[i]->setHoverBgBrush(m_hover);
        }
        else if(property->propertyName() == "HoverlBgBrushB")
        {
            m_hover.setColorAt(1.0, value);
            m_buttons[i]->setHoverBgBrush(m_hover);
        }
        else if(property->propertyName() == "CheckBgBrushR")
        {
            m_check.setColorAt(0.0, value);
            m_buttons[i]->setCheckBgBrush(m_check);
        }
        else if(property->propertyName() == "CheckBgBrushG")
        {
            m_check.setColorAt(0.5, value);
            m_buttons[i]->setCheckBgBrush(m_check);
        }
        else if(property->propertyName() == "CheckBgBrushB")
        {
            m_check.setColorAt(1.0, value);
            m_buttons[i]->setCheckBgBrush(m_check);
        }
        else if(property->propertyName() == "NormalTextColor")
        {
            m_buttons[i]->setNormalTextColor(value);
        }
        else if(property->propertyName() == "HoverTextColor")
        {
            m_buttons[i]->setHoverTextColor(value);
        }
        else if(property->propertyName() == "CheckTextColor")
        {
            m_buttons[i]->setCheckTextColor(value);
        }
    }
}

#include "ttkfunctionlisthwidget.h"

#include <QPainter>
#include <QBoxLayout>

TTKFunctionItemWidget::TTKFunctionItemWidget(QWidget *parent)
    : QWidget(parent),
      m_enterIn(false),
      m_selectedOn(false),
      m_resizeMode(false)
{
    setFixedSize(205, 35);
}

void TTKFunctionItemWidget::setLabelText(const QString &text)
{
    m_text = text;
    update();
}

void TTKFunctionItemWidget::setLabelIcon(const QString &iconf, const QString &iconb)
{
    m_iconf = iconf;
    m_iconb = iconb;
    update();
}

void TTKFunctionItemWidget::setSelectedMode(bool select)
{
    m_selectedOn = select;
    update();
}

void TTKFunctionItemWidget::resizeMode(bool mode)
{
    m_resizeMode = mode;
    setFixedWidth(mode ? 75 : 205);
    update();
}

void TTKFunctionItemWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    m_selectedOn = true;
    Q_EMIT selectedChanged(this);
    update();
}

void TTKFunctionItemWidget::enterEvent(QtEnterEvent *event)
{
    QWidget::enterEvent(event);
    m_enterIn = (m_selectedOn ? false : true);
    update();
}

void TTKFunctionItemWidget::leaveEvent(QEvent *event)
{
    QWidget::leaveEvent(event);
    m_enterIn = false;
    update();
}

void TTKFunctionItemWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    if(m_selectedOn)
    {
        painter.fillRect(rect(), QColor(0, 0, 0, 100));

        QPolygon py;
        py.append(QPoint(width(), height() / 2 - 7));
        py.append(QPoint(width() - 7, height() / 2));
        py.append(QPoint(width(), height() / 2 + 7));
        painter.setPen(Qt::white);
        painter.setBrush(Qt::white);
        painter.drawPolygon(py);
    }
    else
    {
        painter.fillRect(rect(), m_enterIn ? QColor(0, 0, 0, 50) : QColor(0, 0, 0, 0));
    }

    if(!m_resizeMode)
    {
        painter.drawPixmap(45, 8, QPixmap(m_enterIn ? m_iconf : m_iconb));
        painter.setPen(m_enterIn ? QColor(255, 255, 255) : QColor(222, 222, 222));
        painter.drawText(QRect(70, 0, 130, height()), Qt::AlignLeft | Qt::AlignVCenter, m_text);
    }
    else
    {
        QPixmap pix(m_enterIn ? m_iconf : m_iconb);
        painter.drawPixmap((width() - pix.width()) / 2, 8, pix);
    }
}



TTKFunctionListHWidget::TTKFunctionListHWidget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 18, 0, 0);
    layout->setSpacing(0);

    for(int i = 0; i < 3; ++i)
    {
        TTKFunctionItemWidget *item = new TTKFunctionItemWidget(this);
        item->setLabelText("Hello World");
        item->setLabelIcon(QString(), QString());
        connect(item, SIGNAL(selectedChanged(TTKFunctionItemWidget*)), SLOT(selectedChanged(TTKFunctionItemWidget*)));
        layout->addWidget(item);
        m_items << item;
    }

    m_items.front()->setSelectedMode(true);

    layout->addStretch(1);
    setLayout(layout);
}

TTKFunctionListHWidget::~TTKFunctionListHWidget()
{
    qDeleteAll(m_items);
}

void TTKFunctionListHWidget::resizeMode(bool mode)
{
    for(TTKFunctionItemWidget *it : qAsConst(m_items))
    {
        it->resizeMode(mode);
    }
}

void TTKFunctionListHWidget::selectedChanged(TTKFunctionItemWidget *item)
{
    const int index = m_items.indexOf(item);
    if(index == -1)
    {
        return;
    }

    Q_EMIT currentIndexChanged(index);

    for(TTKFunctionItemWidget *it : qAsConst(m_items))
    {
        it->setSelectedMode(false);
    }
    m_items[index]->setSelectedMode(true);
}

void TTKFunctionListHWidget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}

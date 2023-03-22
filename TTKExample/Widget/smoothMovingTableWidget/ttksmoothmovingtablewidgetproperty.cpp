#include "ttksmoothmovingtablewidgetproperty.h"
#include "ttksmoothmovingtablewidget.h"

TTKSmoothMovingTableWidgetProperty::TTKSmoothMovingTableWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new TTKSmoothMovingTableWidget(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObjectCast(TTKSmoothMovingTableWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    m_browser->addProperty(objectItem);

    //
    TTKSmoothMovingTableWidget *widget = TTKObjectCast(TTKSmoothMovingTableWidget*, m_item);
    widget->setColumnCount(1);
    widget->setRowCount(500);
    for(int i = 0; i < widget->rowCount(); ++i)
    {
        widget->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
    }
    widget->setMovedScrollBar(widget->verticalScrollBar());
}

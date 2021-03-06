#include "QOpenFileButtonPlugin.h"
#include "QOpenFileButton.h"

#include <QtPlugin>
#include <QApplication>
#include <QStyle>

QOpenFileButtonPlugin::QOpenFileButtonPlugin(QObject *parent)
    : QObject(parent)
    , m_initialized(false)
{
}

void QOpenFileButtonPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized) {
        return;
    }

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool QOpenFileButtonPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *QOpenFileButtonPlugin::createWidget(QWidget *parent)
{
    return new QOpenFileButton(parent);
}

QString QOpenFileButtonPlugin::name() const
{
    return QLatin1String("QOpenFileButton");
}

QString QOpenFileButtonPlugin::group() const
{
    return QLatin1String("Qt Widgets Extra / File Dialog");
}

QIcon QOpenFileButtonPlugin::icon() const
{
    return QApplication::style()->standardIcon(QStyle::SP_DialogOpenButton);
}

QString QOpenFileButtonPlugin::toolTip() const
{
    return QLatin1String("A tool button that allow to choose an opening file");
}

QString QOpenFileButtonPlugin::whatsThis() const
{
    return toolTip();
}

bool QOpenFileButtonPlugin::isContainer() const
{
    return false;
}

QString QOpenFileButtonPlugin::domXml() const
{
    return QLatin1String("<widget class=\"QOpenFileButton\" name=\"openFileButton\">\n</widget>\n");
}

QString QOpenFileButtonPlugin::includeFile() const
{
    return QLatin1String("QOpenFileButton.h");
}

#ifndef SCRIPTENGINE_H
#define SCRIPTENGINE_H

#include <QObject>

class ScriptEngine : public QObject
{
    Q_OBJECT
public:
    explicit ScriptEngine(QObject *parent = 0);

signals:

public slots:

};

#endif // SCRIPTENGINE_H

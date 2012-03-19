#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include "scriptengine.h"
#include "csseditor.h"
#include "widgetviewer.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void Slot_OpenFile();
    void Slot_SaveFile();
    void Slot_SaveAsFile();
    void Slot_ApplyStyleSheet();
    void Slot_About();
    void Slot_AskToSave();

private:
    void createActions();
    void createMenu();
    void createToolbars();

    void stub();

    QHash<QString, QAction*> _actionHash;

    ScriptEngine* _scriptEngine;
    CSSEditor* _cssEditor;
    WidgetViewer* _widgetViewer;

    QMenu *_fileMenu;
    QMenu *_editMenu;
    QMenu *_helpMenu;
    QToolBar* _mainToolbar;
    QString _currentFile;

};

#endif // MAINWINDOW_H

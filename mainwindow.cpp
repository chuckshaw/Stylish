 #include <QtGui>

#include "mainwindow.h"
#include "scriptengine.h"
#include "csseditor.h"
#include "widgetviewer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    _scriptEngine = NULL;
    _cssEditor = NULL;
    _widgetViewer = NULL;
    _mainToolbar = NULL;
    _fileMenu = NULL;
    _editMenu = NULL;
    _helpMenu = NULL;

    _currentFile = "";

    this->setGeometry(200, 150, 1024, 650);
    this->setWindowTitle("Stylish");

    _cssEditor = new CSSEditor(this);
    this->setCentralWidget(_cssEditor);

    _widgetViewer = new WidgetViewer(this);
    _widgetViewer->setMinimumWidth(250);

    QDockWidget* dockWidget = new QDockWidget("UI Elements", this);
    dockWidget->setWidget(new QScrollArea(this));
    ((QScrollArea*)dockWidget->widget())->setWidget(_widgetViewer);

    this->addDockWidget(Qt::RightDockWidgetArea, dockWidget);
    statusBar()->showMessage(tr("Ready"));

    createMenu();
    createToolbars();
    createActions();
}

MainWindow::~MainWindow()
{
    if(_scriptEngine)
    {
        delete _scriptEngine;
        _scriptEngine = NULL;
    }

    if(_cssEditor)
    {
        delete _cssEditor;
        _cssEditor = NULL;
    }

    if(_widgetViewer)
    {
        delete _widgetViewer;
        _widgetViewer = NULL;
    }

    _actionHash.clear();
}

void MainWindow::createActions()
{
    QAction* openAct = new QAction(QIcon(":/images/Resources/document-open.png"), tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing stylesheet."));
    connect(openAct, SIGNAL(triggered()), this, SLOT(Slot_OpenFile()));
    _mainToolbar->addAction(openAct);
    _fileMenu->addAction(openAct);

    QAction* saveAct = new QAction(QIcon(":/images/Resources/document-save.png"), tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save current stylesheet."));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(Slot_SaveFile()));
    _mainToolbar->addAction(saveAct);
    _fileMenu->addAction(saveAct);

    QAction* saveAsAct = new QAction(QIcon(":/images/Resources/document-save-as.png"), tr("SaveAs"), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Save current stylesheet as..."));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(Slot_SaveAsFile()));
    _mainToolbar->addAction(saveAsAct);
    _fileMenu->addAction(saveAsAct);

    QAction* applyAct = new QAction(QIcon(":/images/Resources/view-refresh.png"), tr("&Apply"), this);
    //applyAct->setShortcuts(QKeySequence::Refresh);
    applyAct->setStatusTip(tr("Apply StyleSheet."));
    connect(applyAct, SIGNAL(triggered()), this, SLOT(Slot_ApplyStyleSheet()));
    _mainToolbar->addAction(applyAct);

    QAction* aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(Slot_About()));
    //_mainToolbar->addAction(aboutAct);
    _helpMenu->addAction(aboutAct);

    /*
    connect(ui.actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui.actionClose, SIGNAL(triggered()), this, SLOT(Slot_CloseProject()));
    connect(ui.actionUndo, SIGNAL(triggered()), this, SLOT(Slot_Undo()));
    connect(ui.actionRedo, SIGNAL(triggered()), this, SLOT(Slot_Redo()));
    connect(ui.actionCut, SIGNAL(triggered()), this, SLOT(Slot_Cut()));
    connect(ui.actionCopy, SIGNAL(triggered()), this, SLOT(Slot_Copy()));
    connect(ui.actionPaste, SIGNAL(triggered()), this, SLOT(Slot_Paste()));
    connect(ui.actionDelete, SIGNAL(triggered()), this, SLOT(Slot_Delete()));
    connect(ui.actionSelect_All, SIGNAL(triggered()), this, SLOT(Slot_SelectAll()));
    */

    /*
    fileMenu->addAction(openAct);
    fileToolBar->addAction(openAct);
    */
}

void MainWindow::createMenu()
{
    _fileMenu = menuBar()->addMenu(tr("&File"));
//    fileMenu->addAction(newAct);
//    fileMenu->addAction(openAct);
//    fileMenu->addAction(saveAct);
//    fileMenu->addAction(printAct);
//    fileMenu->addSeparator();
//    fileMenu->addAction(exitAct);

    _editMenu = menuBar()->addMenu(tr("&Edit"));
//    editMenu->addAction(undoAct);
//    editMenu->addAction(redoAct);
//    editMenu->addSeparator();
//    editMenu->addAction(cutAct);
//    editMenu->addAction(copyAct);
//    editMenu->addAction(pasteAct);
//    editMenu->addSeparator();

    _helpMenu = menuBar()->addMenu(tr("&Help"));
//    helpMenu->addAction(aboutAct);
//    helpMenu->addAction(aboutQtAct);
}

void MainWindow::createToolbars()
{
    _mainToolbar = addToolBar("MainToolBar");
    //_mainToolbar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}

void MainWindow::stub()
{
    QMessageBox msgBox;
    msgBox.setText("Implement me!");
    msgBox.exec();
}

void MainWindow::Slot_OpenFile()
{
    _currentFile = QFileDialog::getOpenFileName(this);
    if (!_currentFile.isEmpty())
    {
        QFile file(_currentFile);
        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, tr("Stylish: Open File"),
                                 tr("Cannot read file %1:\n%2.")
                                 .arg(_currentFile)
                                 .arg(file.errorString()));
            return;
        }

        QTextStream in(&file);
        _cssEditor->editor()->setPlainText(in.readAll());
    }
}

void MainWindow::Slot_SaveFile()
{
    QFile file(_currentFile);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Stylish: Save File"),
                             tr("Cannot open file %1:\n%2.")
                             .arg(_currentFile)
                             .arg(file.errorString()));
        return;
    }

    QTextStream out(&file);
    out << _cssEditor->editor()->toPlainText();
}

void MainWindow::Slot_SaveAsFile()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, tr("Stylish: Save File"),
                                 tr("Cannot open file %1:\n%2.")
                                 .arg(fileName)
                                 .arg(file.errorString()));
            return;
        }

        _currentFile = fileName;
        QTextStream out(&file);
        out << _cssEditor->editor()->toPlainText();
    }
}

void MainWindow::Slot_ApplyStyleSheet()
{
    _widgetViewer->setStyleSheet(_cssEditor->editor()->toPlainText());
}

void MainWindow::Slot_About()
{
    QMessageBox msgBox;
    msgBox.about(this, "About Stylish", "Simple styling utility for Qt based applications. Chuck Shaw (chuck.shaw@gmail.com)");
}

void MainWindow::Slot_AskToSave()
{
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
}

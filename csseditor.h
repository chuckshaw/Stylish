#ifndef CSSEDITOR_H
#define CSSEDITOR_H

#include <QTextEdit>
#include <QtGui>

#include "syntaxhighlighter.h"

class SideBar : public QWidget
{
    Q_OBJECT

public:
    SideBar(QWidget *parent = 0);
    void setTextEdit(QTextEdit* textEdit);
    void paintEvent( QPaintEvent *paintEvent );

private:
    int _currentLine;
    QTextEdit* _textEdit;
};

class CSSEditor : public QFrame
{
    Q_OBJECT

public:
    explicit CSSEditor(QWidget *parent = 0);
    QTextEdit* editor() { return _textEdit; }

signals:

public slots:

private:
    QTextEdit* _textEdit;
    SyntaxHighlighter* _syntaxHighlighter;
    QHBoxLayout *_hboxLayout;
    SideBar* _sideBar;

};

#endif // CSSEDITOR_H

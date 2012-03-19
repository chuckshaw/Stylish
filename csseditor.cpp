#include "csseditor.h"
#include "syntaxhighlighter.h"
#include <QtGui>

SideBar::SideBar(QWidget *parent) :
    QWidget(parent)
{
    _textEdit = NULL;
    _currentLine = 0;
    setFixedWidth(fontMetrics().width(QString("0000")));
}

void SideBar::setTextEdit(QTextEdit* textEdit)
{
    _textEdit = textEdit;
    connect( _textEdit->document()->documentLayout(), SIGNAL( update(const QRectF &) ), this, SLOT( update() ) );
    connect( _textEdit->verticalScrollBar(), SIGNAL(valueChanged(int) ), this, SLOT( update() ) );
}

void SideBar::paintEvent( QPaintEvent *paintEvent )
{
    int lineCount = 0;
    int yValue = _textEdit->verticalScrollBar()->value();
    int height = yValue + _textEdit->viewport()->height();
    const QFontMetrics fm = fontMetrics();
    const int ascent = fm.ascent() + 1;

    QPainter p(this);

    QAbstractTextDocumentLayout *layout = _textEdit->document()->documentLayout();
    QTextDocument* doc = _textEdit->document();


    for (QTextBlock it = doc->begin(); it != doc->end(); it = it.next())
    {
        lineCount++;
        QRectF boundingRect = layout->blockBoundingRect(it);

        QPointF pos = boundingRect.topLeft();
        if(pos.y() + boundingRect.height() < yValue)
        {
            continue;
        }
        if(pos.y() > height)
        {
            break;
        }

        QString lineNumber = QString::number(lineCount);
        p.drawText( width() - fm.width(lineNumber), qRound( pos.y() ) - yValue + ascent, lineNumber );
    }
}

CSSEditor::CSSEditor(QWidget *parent) :
    QFrame(parent)
{
    _textEdit = new QTextEdit(this);
    _textEdit->setLineWrapMode( QTextEdit::NoWrap );
    _textEdit->setFrameStyle( QFrame::NoFrame );
    _syntaxHighlighter = new SyntaxHighlighter(_textEdit->document());

    _sideBar = new SideBar(this);
    _sideBar->setTextEdit(_textEdit);

    _hboxLayout = new QHBoxLayout( this );
    _hboxLayout->setContentsMargins(0,0,0,0);
    this->setLayout(_hboxLayout);

    _hboxLayout->addWidget(_sideBar);
    _hboxLayout->addWidget(_textEdit);
}

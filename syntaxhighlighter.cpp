#include "syntaxhighlighter.h"

SyntaxHighlighter::SyntaxHighlighter(QObject *parent)
    : QSyntaxHighlighter(parent)
{
    setupSyntax();
}

SyntaxHighlighter::SyntaxHighlighter(QTextDocument *parent)
 : QSyntaxHighlighter(parent)
{
    setupSyntax();
}

SyntaxHighlighter::SyntaxHighlighter(QTextEdit *parent)
 : QSyntaxHighlighter(parent)
{
    setupSyntax();
}

void SyntaxHighlighter::setupSyntax()
{
    Rule tmpRule;

    keywordFormat.setForeground(Qt::red);
    //keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\bmargin\\b" << "\\bpadding\\b" << "\\btext-align\\b"
                    << "\\bbackground-color\\b" << "\\bfont-size\\b" << "\\bfont-weight\\b"
                    << "\\bfont-family\\b" << "\\bpadding-top\\b" << "\\bpadding-bottom\\b"
                    << "\\bpadding-right\\b" << "\\bpadding-left\\b" << "\\bborder\\b"
                    << "\\bwidth\\b" << "\\bposition\\b" << "\\bcolor\\b"
                    << "\\btext-decoration\\b" << "\\bheight\\b" << "\\bleft\\b"
                    << "\\bright\\b" << "\\bmargin-top\\b" << "\\bmargin-bottom\\b"
                    << "\\bmargin-left\\b" << "\\bmargin-right\\b" << "\\bbackground\\b"
                    << "\\bsubcontrol\\b" << "\\bimage\\b" << "\\bsubcontrol-origin\\b"
                    << "\\bsubcontrol-position\\b" << "\\bimage-origin\\b" << "\\bimage-url\\b"
                    << "\\burl\\b" << "\\bmin-width\\b" << "\\bborder-radius\\b"
                    << "\\bshow-decoration-selected\\b" << "\\bsection\\b" << "\\balternate-background-color\\b"
                    << "\\bselection-color\\b" << "\\bselection-background-color\\b" << "\\bborder-radius\\b";

    foreach (const QString &pattern, keywordPatterns) {
        tmpRule.pattern = QRegExp(pattern);
        tmpRule.format = keywordFormat;
        Rules.append(tmpRule);
    }

    //classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::blue);
    tmpRule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
    tmpRule.format = classFormat;
    Rules.append(tmpRule);

    singleLineCommentFormat.setForeground(Qt::darkGreen);
    tmpRule.pattern = QRegExp("//[^\n]*");
    tmpRule.format = singleLineCommentFormat;
    Rules.append(tmpRule);

    multiLineCommentFormat.setForeground(Qt::darkGreen);

    quotationFormat.setForeground(Qt::darkGreen);
    tmpRule.pattern = QRegExp("\".*\"");
    tmpRule.format = quotationFormat;
    Rules.append(tmpRule);

    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");
}

void SyntaxHighlighter::highlightBlock (const QString & text)
{
    foreach (const Rule &tmpRule, Rules) {
        QRegExp expression(tmpRule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, tmpRule.format);
            index = expression.indexIn(text, index + length);
        }
    }

    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
    {
        startIndex = text.indexOf(commentStartExpression);
    }

    while (startIndex >= 0)
    {
        int endIndex = text.indexOf(commentEndExpression, startIndex);
        int commentLength;
        if (endIndex == -1)
        {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        }
        else
        {
            commentLength = endIndex - startIndex + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }
}

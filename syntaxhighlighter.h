#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QObject>
#include <QTextDocument>
#include <QTextEdit>
#include <QSyntaxHighlighter>

#include <QHash>
#include <QTextCharFormat>

class SyntaxHighlighter : public QSyntaxHighlighter
{
public:
    SyntaxHighlighter(QObject *parent);
    SyntaxHighlighter(QTextDocument *parent);
    SyntaxHighlighter(QTextEdit *parent);

    virtual void highlightBlock (const QString & text);

private:
    void setupSyntax();

    QRegExp commentStartExpression;
    QRegExp commentEndExpression;

    struct Rule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };

    QVector<Rule> Rules;

    QTextCharFormat keywordFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat classFormat;

};

#endif // SYNTAXHIGHLIGHTER_H

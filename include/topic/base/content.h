#ifndef EASYLEARNER_CONTENT_H
#define EASYLEARNER_CONTENT_H


#include <string>
#include <QString>
#include <map>

class Content {
public:
    Content(const QString &topicName);

    static void addIntoDefinitionMap(const QString &term, const QString &definition);

    static std::map<QString, QString> getDefinitionMap();

    static void addIntoQuestionMap(const QString &question, const QString &answer);

    static std::map<QString, QString> getQuestionMap();

private:
    static std::map<QString, QString> definitionMap;
    static std::map<QString, QString> questionMap;
};


#endif //EASYLEARNER_CONTENT_H

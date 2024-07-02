#include "../../../include/topic/base/content.h"

std::map<QString, QString> Content::definitionMap;
std::map<QString, QString> Content::questionMap;

Content::Content(const QString &topicName) {
    // DELETE THIS
    definitionMap["Term"] = "definition";
    questionMap["Question"] = "answer";
    // THIS IS FOR TESTING
}

void Content::addIntoDefinitionMap(const QString &term, const QString &definition) {
    definitionMap[term] = definition;
}

std::map<QString, QString> Content::getDefinitionMap() {
    return definitionMap;
}

void Content::addIntoQuestionMap(const QString &question, const QString &answer) {
    questionMap[question] = answer;
}

std::map<QString, QString> Content::getQuestionMap() {
    return questionMap;
}


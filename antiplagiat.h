#pragma once
#include <string>
#include <set>
#include <msclr/marshal_cppstd.h>
#include "smart_ptr .h"

class Antiplagiat {
private:
    std::set<std::string> database;

public:
    Antiplagiat() {
        database = {
            "год", "человек", "врем€", "дело", "жизнь", "день", "рука", "раз",
            "работа", "слово", "место", "лицо", "друг", "глаз", "вопрос", "дом",
            "сторона", "страна", "мир", "случай", "голова", "ребенок", "сила",
            "конец", "вид", "система", "часть", "город", "отношение", "женщина",
            "деньги", "земл€", "машина", "вода", "отец", "проблема", "час",
            "право", "нога", "решение", "дверь", "образ", "истори€", "власть",
            "закон", "война", "бог", "голос", "тыс€ча", "книга", "текст"
        };
    }

    // ѕодсчЄт слов
    int CountWords(System::String^ text) {
        array<wchar_t>^ delimiters = { ' ', '\t', '\n', '\r', '.', ',', '!', '?', ';', ':', '(', ')', '-', '_' };
        auto words = text->Split(delimiters, System::StringSplitOptions::RemoveEmptyEntries);
        return words->Length;
    }

    // ѕодсчЄт символов без пробелов
    int CountCharsWithoutSpaces(System::String^ text) {
        System::String^ cleaned = text->Replace(" ", "")->Replace("\t", "")->Replace("\n", "")->Replace("\r", "");
        return cleaned->Length;
    }

    // ѕодсчЄт всех символов
    int CountTotalChars(System::String^ text) {
        return text->Length;
    }

    // ѕроверка на плагиат
    double CheckOriginality(System::String^ text) {
        array<wchar_t>^ delimiters = { ' ', '\t', '\n', '\r', '.', ',', '!', '?', ';', ':', '(', ')', '-', '_' };
        auto words = text->Split(delimiters, System::StringSplitOptions::RemoveEmptyEntries);
        int totalWords = words->Length;
        if (totalWords == 0) return 0.0;

        int plagiarized = 0;

        for each (System::String ^ word in words) {
            std::string stdWord = msclr::interop::marshal_as<std::string>(word->ToLower()->Trim());
            if (database.find(stdWord) != database.end()) {
                plagiarized++;
            }
        }

        return ((double)(totalWords - plagiarized) / totalWords) * 100.0;
    }
};
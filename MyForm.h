#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <set>
#include <iterator>
#include <msclr/marshal_cppstd.h>
#include <sstream>
#include "smart_ptr .h"
#include "antiplagiat.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace AntiplagiatApp {
    public ref class MyForm : public System::Windows::Forms::Form {
    public:
        MyForm(void)
        {
            InitializeComponent();
            antiplagiat = new smart_ptr<Antiplagiat>(new Antiplagiat());
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
                delete antiplagiat;
            }
        }

    private:
        System::Windows::Forms::RichTextBox^ TextBox;
        System::Windows::Forms::Button^ buttonCheckOriginality;
        System::Windows::Forms::OpenFileDialog^ openFileDialog1;
        System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
        System::Windows::Forms::Label^ labelTextCountChars;
        System::Windows::Forms::Label^ labelTextCountCharsWithoutSpaces;
        System::Windows::Forms::Label^ labelTextCoutWord;
        System::Windows::Forms::Label^ labelCountChars;
        System::Windows::Forms::Label^ labelCountCharsWithoutSpaces;
        System::Windows::Forms::Label^ labelCountWord;
        System::Windows::Forms::MenuStrip^ menuStrip1;
        System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ сохранитьToolStripMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ загрузитьToolStripMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ выйтиToolStripMenuItem;
        System::Windows::Forms::Label^ labelSaveFile;
        System::Windows::Forms::Label^ labelOriginality;
        System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem;
        System::ComponentModel::Container^ components;
        smart_ptr<Antiplagiat>* antiplagiat;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->TextBox = (gcnew System::Windows::Forms::RichTextBox());
               this->buttonCheckOriginality = (gcnew System::Windows::Forms::Button());
               this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
               this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
               this->labelTextCountChars = (gcnew System::Windows::Forms::Label());
               this->labelTextCountCharsWithoutSpaces = (gcnew System::Windows::Forms::Label());
               this->labelTextCoutWord = (gcnew System::Windows::Forms::Label());
               this->labelCountChars = (gcnew System::Windows::Forms::Label());
               this->labelCountCharsWithoutSpaces = (gcnew System::Windows::Forms::Label());
               this->labelCountWord = (gcnew System::Windows::Forms::Label());
               this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
               this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->сохранитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->загрузитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->выйтиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->labelSaveFile = (gcnew System::Windows::Forms::Label());
               this->labelOriginality = (gcnew System::Windows::Forms::Label());
               this->menuStrip1->SuspendLayout();
               this->SuspendLayout();
               // 
               // TextBox
               // 
               this->TextBox->Location = System::Drawing::Point(12, 45);
               this->TextBox->Name = L"TextBox";
               this->TextBox->Size = System::Drawing::Size(1379, 528);
               this->TextBox->TabIndex = 0;
               this->TextBox->Text = L"";
               // 
               // buttonCheckOriginality
               // 
               this->buttonCheckOriginality->Location = System::Drawing::Point(1068, 592);
               this->buttonCheckOriginality->Name = L"buttonCheckOriginality";
               this->buttonCheckOriginality->Size = System::Drawing::Size(267, 76);
               this->buttonCheckOriginality->TabIndex = 16;
               this->buttonCheckOriginality->Text = L"Проверить на плагиат";
               this->buttonCheckOriginality->UseVisualStyleBackColor = true;
               this->buttonCheckOriginality->Click += gcnew System::EventHandler(this, &MyForm::buttonCheckOriginality_Click);
               // 
               // openFileDialog1
               // 
               this->openFileDialog1->Filter = L"Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";
               // 
               // saveFileDialog1
               // 
               this->saveFileDialog1->Filter = L"Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";
               // 
               // labelTextCountChars
               // 
               this->labelTextCountChars->AutoSize = true;
               this->labelTextCountChars->Location = System::Drawing::Point(34, 583);
               this->labelTextCountChars->Name = L"labelTextCountChars";
               this->labelTextCountChars->Size = System::Drawing::Size(152, 16);
               this->labelTextCountChars->TabIndex = 15;
               this->labelTextCountChars->Text = L"Количество символов";
               // 
               // labelTextCountCharsWithoutSpaces
               // 
               this->labelTextCountCharsWithoutSpaces->AutoSize = true;
               this->labelTextCountCharsWithoutSpaces->Location = System::Drawing::Point(352, 583);
               this->labelTextCountCharsWithoutSpaces->Name = L"labelTextCountCharsWithoutSpaces";
               this->labelTextCountCharsWithoutSpaces->Size = System::Drawing::Size(99, 16);
               this->labelTextCountCharsWithoutSpaces->TabIndex = 14;
               this->labelTextCountCharsWithoutSpaces->Text = L"Без пробелов";
               // 
               // labelTextCoutWord
               // 
               this->labelTextCoutWord->AutoSize = true;
               this->labelTextCoutWord->Location = System::Drawing::Point(598, 583);
               this->labelTextCoutWord->Name = L"labelTextCoutWord";
               this->labelTextCoutWord->Size = System::Drawing::Size(119, 16);
               this->labelTextCoutWord->TabIndex = 13;
               this->labelTextCoutWord->Text = L"Количество слов";
               // 
               // labelCountChars
               // 
               this->labelCountChars->AutoSize = true;
               this->labelCountChars->Location = System::Drawing::Point(86, 609);
               this->labelCountChars->Name = L"labelCountChars";
               this->labelCountChars->Size = System::Drawing::Size(0, 16);
               this->labelCountChars->TabIndex = 12;
               // 
               // labelCountCharsWithoutSpaces
               // 
               this->labelCountCharsWithoutSpaces->AutoSize = true;
               this->labelCountCharsWithoutSpaces->Location = System::Drawing::Point(379, 609);
               this->labelCountCharsWithoutSpaces->Name = L"labelCountCharsWithoutSpaces";
               this->labelCountCharsWithoutSpaces->Size = System::Drawing::Size(0, 16);
               this->labelCountCharsWithoutSpaces->TabIndex = 11;
               // 
               // labelCountWord
               // 
               this->labelCountWord->AutoSize = true;
               this->labelCountWord->Location = System::Drawing::Point(635, 609);
               this->labelCountWord->Name = L"labelCountWord";
               this->labelCountWord->Size = System::Drawing::Size(0, 16);
               this->labelCountWord->TabIndex = 10;
               // 
               // menuStrip1
               // 
               this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
               this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
                   this->файлToolStripMenuItem,
                       this->справкаToolStripMenuItem
               });
               this->menuStrip1->Location = System::Drawing::Point(0, 0);
               this->menuStrip1->Name = L"menuStrip1";
               this->menuStrip1->Size = System::Drawing::Size(1401, 28);
               this->menuStrip1->TabIndex = 17;
               this->menuStrip1->Text = L"menuStrip1";
               // 
               // файлToolStripMenuItem
               // 
               this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
                   this->сохранитьToolStripMenuItem,
                       this->загрузитьToolStripMenuItem, this->выйтиToolStripMenuItem
               });
               this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
               this->файлToolStripMenuItem->Size = System::Drawing::Size(59, 24);
               this->файлToolStripMenuItem->Text = L"Файл";
               // 
               // сохранитьToolStripMenuItem
               // 
               this->сохранитьToolStripMenuItem->Name = L"сохранитьToolStripMenuItem";
               this->сохранитьToolStripMenuItem->Size = System::Drawing::Size(166, 26);
               this->сохранитьToolStripMenuItem->Text = L"Сохранить";
               this->сохранитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::сохранитьToolStripMenuItem_Click);
               // 
               // загрузитьToolStripMenuItem
               // 
               this->загрузитьToolStripMenuItem->Name = L"загрузитьToolStripMenuItem";
               this->загрузитьToolStripMenuItem->Size = System::Drawing::Size(166, 26);
               this->загрузитьToolStripMenuItem->Text = L"Загрузить";
               this->загрузитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::загрузитьToolStripMenuItem_Click);
               // 
               // выйтиToolStripMenuItem
               // 
               this->выйтиToolStripMenuItem->Name = L"выйтиToolStripMenuItem";
               this->выйтиToolStripMenuItem->Size = System::Drawing::Size(166, 26);
               this->выйтиToolStripMenuItem->Text = L"Выйти";
               this->выйтиToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::выйтиToolStripMenuItem_Click);
               // 
               // справкаToolStripMenuItem
               // 
               this->справкаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->оПрограммеToolStripMenuItem });
               this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
               this->справкаToolStripMenuItem->Size = System::Drawing::Size(81, 24);
               this->справкаToolStripMenuItem->Text = L"Справка";
               // 
               // оПрограммеToolStripMenuItem
               // 
               this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
               this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(187, 26);
               this->оПрограммеToolStripMenuItem->Text = L"О программе";
               this->оПрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::оПрограммеToolStripMenuItem_Click);
               // 
               // labelSaveFile
               // 
               this->labelSaveFile->AutoSize = true;
               this->labelSaveFile->Location = System::Drawing::Point(405, 631);
               this->labelSaveFile->Name = L"labelSaveFile";
               this->labelSaveFile->Size = System::Drawing::Size(0, 16);
               this->labelSaveFile->TabIndex = 17;
               // 
               // labelOriginality
               // 
               this->labelOriginality->AutoSize = true;
               this->labelOriginality->Location = System::Drawing::Point(34, 661);
               this->labelOriginality->Name = L"labelOriginality";
               this->labelOriginality->Size = System::Drawing::Size(140, 16);
               this->labelOriginality->TabIndex = 19;
               this->labelOriginality->Text = L"Оригинальность: 0%";
               // 
               // MyForm
               // 
               this->ClientSize = System::Drawing::Size(1401, 696);
               this->Controls->Add(this->labelOriginality);
               this->Controls->Add(this->labelSaveFile);
               this->Controls->Add(this->buttonCheckOriginality);
               this->Controls->Add(this->labelCountWord);
               this->Controls->Add(this->labelCountCharsWithoutSpaces);
               this->Controls->Add(this->labelCountChars);
               this->Controls->Add(this->labelTextCoutWord);
               this->Controls->Add(this->labelTextCountCharsWithoutSpaces);
               this->Controls->Add(this->labelTextCountChars);
               this->Controls->Add(this->TextBox);
               this->Controls->Add(this->menuStrip1);
               this->MainMenuStrip = this->menuStrip1;
               this->Name = L"MyForm";
               this->Text = L"Антиплагиат";
               this->menuStrip1->ResumeLayout(false);
               this->menuStrip1->PerformLayout();
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion

    private: System::Void buttonCheckOriginality_Click(System::Object^ sender, System::EventArgs^ e) {
        // Получаем текст из RichTextBox
        String^ text = TextBox->Text;

        // Подсчёт символов
        labelCountChars->Text = antiplagiat->get()->CountTotalChars(text).ToString();
        labelCountCharsWithoutSpaces->Text = antiplagiat->get()->CountCharsWithoutSpaces(text).ToString();
        labelCountWord->Text = antiplagiat->get()->CountWords(text).ToString();

        double originality = antiplagiat->get()->CheckOriginality(text);
        labelOriginality->Text = "Оригинальность: " + originality.ToString("F2") + "%";
    }

    private: System::Void сохранитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            String^ fileName = saveFileDialog1->FileName;
            try {
                System::IO::File::WriteAllText(fileName, "Отчет о проверке на плагиат:\n\n");
                System::IO::File::AppendAllText(fileName, "Текст: \n" + TextBox->Text);
                System::IO::File::AppendAllText(fileName, "\n\nКоличество символов: " + labelCountChars->Text);
                System::IO::File::AppendAllText(fileName, "\nКоличество слов: " + labelCountWord->Text);
                System::IO::File::AppendAllText(fileName, "\nКоличество символов без пробелов: " + labelCountCharsWithoutSpaces->Text);
                System::IO::File::AppendAllText(fileName, "\nПроцент оригинальности: " + labelOriginality->Text);
                labelSaveFile->Text = "Отчет сохранен успешно!";
            }
            catch (System::Exception^ ex) {
                labelSaveFile->Text = "Ошибка при сохранении отчета: " + ex->Message;
            }
        }
    }

    private: System::Void загрузитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            String^ fileName = openFileDialog1->FileName;
            try {
                TextBox->Text = System::IO::File::ReadAllText(fileName);
            }
            catch (System::Exception^ ex) {
                labelSaveFile->Text = "Ошибка при загрузке файла: " + ex->Message;
            }
        }
    }

    private: System::Void выйтиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        Application::Exit();
    }

    private: System::Void оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        MessageBox::Show("Программа для проверки текста на плагиат.");
    }
    };
}

﻿#include "MyForm.h" 

using namespace System;
using namespace System::Windows::Forms;
using namespace AntiplagiatApp; 

[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    MyForm^ form = gcnew MyForm();
    Application::Run(form);

    return 0;
}

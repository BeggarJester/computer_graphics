#include "MyForm.h" 
#include <Windows.h>


using namespace KGlab1;

//int main(array<System::String^>^ args)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm);
    return 0;
}


#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <winternl.h>
#include <winioctl.h>
#include <evntprov.h>
#include <winevt.h>
#include <comdef.h>

#pragma comment(lib, "wevtapi.lib")
#pragma comment(lib, "advapi32.lib")

#include "UsnJournalAnalyzer.h"
#include "EventLogAnalyzer.h"
#include "ConsoleColors.h"
#include "TamperingDetector.h"

int main() {
    ConsoleColors::Initialize();

    std::cout << ConsoleColors::CYAN << R"(
   _____ _               _                          _____ 
  / ____| |             | |                   /\   / ____|
 | (___ | |__   __ _  __| | _____      __    /  \ | |      
  \___ \| '_ \ / _` |/ _` |/ _ \ \ /\ / /   / /\ \| |      
  ____) | | | | (_| | (_| | (_) \ V  V /   / ____ \ |____ 
 |_____/|_| |_|\__,_|\__,_|\___/ \_/\_/   /_/    \_\_____|
                                                                   
    USN Journal Tampering Detection System
)" << ConsoleColors::RESET << std::endl;

    std::cout << ConsoleColors::YELLOW << "Initializing ShadowAC1..." << ConsoleColors::RESET << std::endl;

    try {
        TamperingDetector detector;
        detector.RunFullAnalysis();
    }
    catch (const std::exception& e) {
        std::cout << ConsoleColors::RED << "Fatal Error: " << e.what() << ConsoleColors::RESET << std::endl;
        return 1;
    }

    std::cout << ConsoleColors::GREEN << "\nAnalysis complete. Press any key to exit..." << ConsoleColors::RESET << std::endl;
    std::cin.get();
    return 0;
}

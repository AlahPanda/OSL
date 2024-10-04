#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main (){
    string resposta1, resposta2,HDDouSSD, compactacao;
    int processo;
///HDD
string comando1HDD = "fsutil behavior set disableLastAccess 2";
string comando2HDD = "fsutil behavior set disable8dot3 0";

///SSD
string comando1SSD = "fsutil behavior set disableLastAccess 0";
string comando2SSD = "fsutil behavior set disable8dot3 1";

//ultra compactaçãos
string ultraCompac = "compact /c /s /a /f /q /i /exe:LZX";

//basica compactação 
string basicoCompact = "/CompactOs:always";

//Parar Serviços 
string servicos1 = "sc stop SysMain";
string servicos2 = "sc stop wisvc";
string servicos3 = "sc stop icssvc";
string servicos4 = "sc stop Fax";
string servicos5 = "sc stop SessionEnv";
string servicos6 = "sc stop TermService";
string servicos7 = "sc stop bthserv";
string servicos8 = "sc stop TabletInputService";
string servicos9 = "sc stop DiagTrack";
string servicos10 = "sc stop DPS";
string servicos11 = "sc stop DoSvc";
string servicos12 = "sc stop WpnService";

//Twearks placebo
 string placebo[] = {
        "Reg.exe add \"HKCU\\Control Panel\\Desktop\" /v \"AutoEndTasks\" /t REG_SZ /d \"1\" /f",
        "Reg.exe add \"HKCU\\Control Panel\\Desktop\" /v \"HungAppTimeout\" /t REG_SZ /d \"1000\" /f",
        "Reg.exe add \"HKCU\\Control Panel\\Desktop\" /v \"WaitToKillAppTimeout\" /t REG_SZ /d \"2000\" /f",
        "Reg.exe add \"HKCU\\Control Panel\\Desktop\" /v \"LowLevelHooksTimeout\" /t REG_SZ /d \"1000\" /f",
        "Reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\FrameServer\" /v \"EnableFrameServerMode\" /t REG_DWORD /d \"1\" /f",
        "Reg.exe add \"HKCU\\Control Panel\\Desktop\" /v \"MenuShowDelay\" /t REG_SZ /d \"320\" /f",
        "Reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\" /v \"ThreadBoostType\" /t REG_DWORD /d \"1\" /f",
        "Reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\" /v \"ThreadSchedulingModel\" /t REG_DWORD /d \"2\" /f",
        "Reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\" /v \"WaitToKillServiceTimeout\" /t REG_SZ /d \"2000\" /f"
    };
    string autologgerLeve[] = {
        "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\AppModel\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\Cellcore\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\Circular Kernel Context Logger\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\CloudExperienceHostOobe\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\DataMarket\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\DefenderApiLogger\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\DefenderAuditLogger\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\DiagLog\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\HolographicDevice\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\iclsClient\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\iclsProxy\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\LwtNetLog\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\Mellanox-Kernel\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\Microsoft-Windows-AssignedAccess-Trace\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\Microsoft-Windows-Setup\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\NBSMBLOGGER\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\PEAuthLog\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\RdrLog\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\ReadyBoot\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\SetupPlatform\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\SetupPlatformTel\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\SocketHeciServer\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\SpoolerLogger\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\SQMLogger\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\TCPIPLOGGER\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\TileStore\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\Tpm\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\TPMProvisioningService\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\UBPM\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\WdiContextLog\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\WFP-IPsec Trace\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\WiFiDriverIHVSession\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\WiFiDriverIHVSessionRepro\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\WiFiSession\" /v \"Start\" /t REG_DWORD /d \"0\" /f",
    "reg.exe add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\WinPhoneCritical\" /v \"Start\" /t REG_DWORD /d \"0\" /f"
    };

    string Direct[]= {
"reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\DirectDraw\" /v \"DisableAGPSupport\" /t REG_DWORD /d \"0\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Wow6432Node\\Microsoft\\DirectDraw\" /v \"DisableAGPSupport\" /t REG_DWORD /d \"0\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\DirectDraw\" /v \"UseNonLocalVidMem\" /t REG_DWORD /d \"1\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Wow6432Node\\Microsoft\\DirectDraw\" /v \"UseNonLocalVidMem\" /t REG_DWORD /d \"1\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\DirectDraw\" /v \"DisableDDSCAPSInDDSD\" /t REG_DWORD /d \"0\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Wow6432Node\\Microsoft\\DirectDraw\" /v \"DisableDDSCAPSInDDSD\" /t REG_DWORD /d \"0\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\DirectDraw\" /v \"EmulationOnly\" /t REG_DWORD /d \"0\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Wow6432Node\\Microsoft\\DirectDraw\" /v \"EmulationOnly\" /t REG_DWORD /d \"0\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\DirectDraw\" /v \"EmulatePointSprites\" /t REG_DWORD /d \"0\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Wow6432Node\\Microsoft\\DirectDraw\" /v \"EmulatePointSprites\" /t REG_DWORD /d \"0\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\DirectDraw\" /v \"EmulateStateBlocks\" /t REG_DWORD /d \"0\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Wow6432Node\\Microsoft\\DirectDraw\" /v \"EmulateStateBlocks\" /t REG_DWORD /d \"0\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\DirectDraw\" /v \"DisableMMX\" /t REG_DWORD /d \"0\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Wow6432Node\\Microsoft\\DirectDraw\" /v \"DisableMMX\" /t REG_DWORD /d \"0\" /f"
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\Direct3D\" /v \"UseNonLocalVidMem\" /t REG_DWORD /d \"1\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Wow6432Node\\Microsoft\\Direct3D\" /v \"UseNonLocalVidMem\" /t REG_DWORD /d \"1\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\Direct3D\" /v \"EnableDebugging\" /t REG_DWORD /d \"0\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\Direct3D\" /v \"FullDebug\" /t REG_DWORD /d \"0\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\Direct3D\" /v \"DisableDM\" /t REG_DWORD /d \"1\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\Direct3D\" /v \"EnableMultimonDebugging\" /t REG_DWORD /d \"0\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\Direct3D\" /v \"LoadDebugRuntime\" /t REG_DWORD /d \"0\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\Direct3D\\Drivers\" /v \"EnumReference\" /t REG_DWORD /d \"1\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Wow6432Node\\Microsoft\\Direct3D\\Drivers\" /v \"EnumReference\" /t REG_DWORD /d \"1\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\Direct3D\\Drivers\" /v \"EnumSeparateMMX\" /t REG_DWORD /d \"1\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Wow6432Node\\Microsoft\\Direct3D\\Drivers\" /v \"EnumSeparateMMX\" /t REG_DWORD /d \"1\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\Direct3D\\Drivers\" /v \"EnumRamp\" /t REG_DWORD /d \"1\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Wow6432Node\\Microsoft\\Direct3D\\Drivers\" /v \"EnumRamp\" /t REG_DWORD /d \"1\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\Direct3D\\Drivers\" /v \"EnumNullDevice\" /t REG_DWORD /d \"1\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Wow6432Node\\Microsoft\\Direct3D\\Drivers\" /v \"EnumNullDevice\" /t REG_DWORD /d \"1\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\Direct3D\" /v \"FewVertices\" /t REG_DWORD /d \"1\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Wow6432Node\\Microsoft\\Direct3D\" /v \"FewVertices\" /t REG_DWORD /d \"1\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\Direct3D\" /v \"DisableVidMemVBs\" /t REG_DWORD /d \"0\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\Direct3D\" /v \"MMX Fast Path\" /t REG_DWORD /d \"1\" /f",
        "reg.exe add \"HKLM\\SOFTWARE\\Microsoft\\Direct3D\" /v \"FlipNoVsync\" /t REG_DWORD /d \"1\" /f"
    };
    string bcedit[]={
    "bcdedit /set useplatformtick yes && "
    "bcdedit /set disabledynamictick yes && "
    "bcdedit /set nx optout && "
    "bcdedit /set bootux disabled && "
    "bcdedit /set bootmenupolicy standard && "
    "bcdedit /set hypervisorlaunchtype off && "
    "bcdedit /set tpmbootentropy ForceDisable && "
    "bcdedit /set quietboot yes && "
    "bcdedit /set linearaddress57 OptOut && "
    "bcdedit /set increaseuserva 268435328 && "
    "bcdedit /set firstmegabytepolicy UseAll && "
    "bcdedit /set avoidlowmemory 0x8000000 && "
    "bcdedit /set nolowmem Yes && "
    "bcdedit /set allowedinmemorysettings 0x0 && "
    "bcdedit /set isolatedcontext No"
    };

    cout << "Seja bem vindo ao software de otimização, aviso ele apenas serve para sistemas windows\nEstamos entendidos??";
    cout << "Digite 'SIM'\n";
    while (true){
        cin >> resposta1;
        if (resposta1=="SIM") {
        cout << "Otimo, bom saber então, estás avisado!";
        break;
        }else if(resposta1=="nao"){
            cout << "Assim seja dito então";
            return 0;
            }else {
            cout << "Praticamente o inimigo da seleção natural\n Digite 'SIM' para prosseguir";
        }
    }

    cout << "Escolha uma opção de otimização:\n";
    cout << "1. HSD Tweaks\n";
    cout << "2. Compactação de disco\n";
    cout << "3. Desativar Serviços\n";
    cout << "4. Tweaks placebo\n";
    cout << "5. Desativar autologger\n";
    cout << "6. DirectDraw & DirectX 3D tweaks\n";
    //Em desenvolvimento (espectativa de 700 linhas restantes)
    /*cout << "7. Otimização bcedit\n";
    cout << "8. Otimização de CPU\n";
    cout << "9. IO Tweaks\n";
    cout << "10. Tweaks de energia\n";
    cout << "11. Tweaks de memória\n";
    cout << "12. Tweaks de USB\n";
    cout << "13. BIOS (AMD/INTEL)\n";
    cout << "14. Kernel tweaks\n";
    cout << "15. Desativar autologger (Complexa)\n";
    cout << "Para pag2 Digite 'pag2'\n";*/
    cin >> processo;
    if (processo==1){
        while (true){
            cout << "por acaso seria HDD ou SSD?\n";
            cin >> HDDouSSD;
            if (HDDouSSD=="HDD"){
                system(comando1HDD.c_str());
                system(comando2HDD.c_str());
                break;
            }else if (HDDouSSD=="SSD"){
                system(comando1SSD.c_str());
                system(comando2SSD.c_str());
                break;
            }else
            cout << "Responda corretamente!\n";
        }
    }else if(processo==2){
        while(true){
            cout << "Por acaso seria ULTRA compactação ou BASICA?\n";
            cin >> compactacao;
            if (compactacao=="ULTRA"){
                system(ultraCompac.c_str());
                break;
            }else if(compactacao=="BASICA"){
            system(basicoCompact.c_str());
            break;
         }else
         cout << "Responda corretamente!\n";
        }

    } else if(processo==3){
        system(servicos1.c_str());
        system(servicos2.c_str());
        system(servicos3.c_str());
        system(servicos4.c_str());
        system(servicos5.c_str());
        system(servicos6.c_str());
        system(servicos7.c_str());
        system(servicos8.c_str());
        system(servicos9.c_str());
        system(servicos10.c_str());
        system(servicos11.c_str());
        system(servicos12.c_str());      
    }else if (processo==4){
        for (const string& comando : placebo){
            system(comando.c_str());
        }
    }else if (processo==5){
        for(const string& comando : autologgerLeve){
            system(comando.c_str());
        }

    }else if(processo==6){
        for(const string& comando: Direct){
            system(comando.c_str());
        }

    }else if(processo==7){
        for(const string& comando: bcedit){
            system(comando.c_str());
        }
    }
   return 0;
}
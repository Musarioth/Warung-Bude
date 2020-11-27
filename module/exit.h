#include <stdio.h>
#include <stdlib.h>

void art(){
    puts("");
    puts("                                                      ..`                                           ");
    puts("                  .//.                               /+++-   `    :/:                               ");
    puts("                  /MM:                               -/+/` .hm/   dMd                               ");
    puts("         :osso/`  /MM:   `+ss+:ss-  `/osso:   /so:sy: ss/ +yMMhs: dMd/sso:   +s+/sso-.+sso:         ");
    puts("        hMdo+dMm. /MM:  .NMNyyNMM/ .NMmsyNMh  yMMmss- MMy :oMMy/- dMMdshMMo  mMMdsdMMMdshMMs        ");
    puts("        .-:--+MM/ /MM:  +MM-  /MM/ sMM`  +MM- yMM`    MMy  -MM+   dMm   dMm  mMm   mMm   hMN        ");
    puts("       `hMmhyhMM/ /MM:  +MM-  /MM/ sMM   /MM: yMM     MMy  -MM+   dMd   dMm  mMd   dMm   yMM        ");
    puts("       :MM+  +MM/ :MMo. .NMmsyNMM/ +MM+..yMM. yMM     MMy  -MMs`  dMd   dMm  mMd   dMm   yMM        ");
    puts("        sNMMNdMM/  smMM- `+syo+MM/  omMMMNh:  yMM     MMs   omMM: dMd   hMm  dMd   dMm   yMN        ");
    puts("         ``.` ``     `` .dds::hMm`  `..-..`````..`````...````....`...```...``...............        ");
    puts("                         -shhhyo`  `..............------------------------------------------        ");
    puts("                                   .+-/`   /::/    :::/`  .-o-`  `/::    -/    -o  :+   -/::        ");
    puts("                                   .s:s`  -+  /:  .o  :/    s    s`     `y+/   :++./s   //-+        ");
    puts("                                   .o-+.  `+--+`   +--/.    o    -/--   +.`+`  :-/+ o   :-`         ");
    puts("                                    ```     ``      ``      `     ```   `         ` `               ");
}

void exit_screen(){
    puts("Please expand your terminal to full screen!");
    printf("press enter to continue");
    getchar();
    system("clear");
    art();
    getchar();
}

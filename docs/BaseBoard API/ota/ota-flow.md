# OTA

## OTA Flow
This page explains the steps for performing an OTA and the necessary libraries.

* Extract the FW image and folder to the robot's PC.
* Move to the folder where you extracted the files.
    - The image and folder contain the `update_firmware.py` script file for OTA.
    ![OTA file image](../../assets/OTA.png)
* Run the firmware update script.
    * If there is already a process communicating with the FW, the script `cannot use the TCP/UDP ports`, so you must terminate the related process before running the script.
    * In `bear`, stop all Docker containers before running the script.

```shell
python3 update_firmware.py --debug binaries/
```

* If an error message appears indicating that `xxx` is missing depending on the robot's operating system, you need to `manually install the Python package`.

```shell
sudo pip3 install pytz
```

```shell
sudo pip3 install tftpy
```

```shell
sudo pip3 install pyyaml
```

* The log below is the log when OTA proceeded normally. If a problem occurs, compare it with the log below.

```powershell
$ python3 update_firmware.py --debug binaries/
[2026-03-22 21:05:43,486][root][DEBUG] Sent command 9 to baseboard
[2026-03-22 21:05:43,486][root][DEBUG] Aethon folder found for Aethon robot type.
[2026-03-22 21:05:43,486][root][INFO] Targets are ['base', 'motor']
[2026-03-22 21:05:44,728][root][WARNING] Cannot find FirmwareUpdate in robotics_analytics_pb
[2026-03-22 21:05:44,728][root][INFO] OTA started.
[2026-03-22 21:05:44,729][root][DEBUG] Sent command 9 to baseboard
[2026-03-22 21:05:46,737][root][DEBUG] Sent command 11 to baseboard
[2026-03-22 21:05:46,737][root][INFO] Current Motor Pcb Version : 15
[2026-03-22 21:05:46,737][root][INFO] Checking OTA precondition.
[2026-03-22 21:05:46,737][root][INFO] Flashing base (Base (3.8.0.0) >>>> Base (3.8.2.2))
[2026-03-22 21:05:46,738][utils.updater][DEBUG] Updater starting with requested options: {'blksize': 1280}

[2026-03-22 21:05:46,752][utils.updater][DEBUG] sending file binaries/Aethon/BaseBoard.bin

[2026-03-22 21:05:46,752][utils.updater][DEBUG] file length: 444416

[2026-03-22 21:05:47,550][utils.updater][DEBUG] file crc: 1133339777

[2026-03-22 21:05:47,595][utils.updater][DEBUG] Asking baseboard to start OTA task...
[2026-03-22 21:05:50,189][utils.updater][DEBUG] TFTP server initialized
[2026-03-22 21:05:50,190][utils.updater][DEBUG] Starting TFTP upload attempt
[2026-03-22 21:05:50,190][utils.updater][DEBUG] Checking upload status
[2026-03-22 21:05:50,190][utils.updater][DEBUG] Tftpy client connected.
[2026-03-22 21:05:50,190][utils.updater][DEBUG] Starting upload of binaries/Aethon/BaseBoard.bin
[2026-03-22 21:05:50,190][tftpy.TftpContext][DEBUG] Sending tftp upload request to 10.2.98.200
[2026-03-22 21:05:50,190][tftpy.TftpContext][DEBUG]     filename -> BaseBoard.bin
[2026-03-22 21:05:50,190][tftpy.TftpContext][DEBUG]     options -> {'blksize': 1280}
[2026-03-22 21:05:50,191][utils.updater][DEBUG] TFTP download request received.
[2026-03-22 21:05:50,192][utils.updater][DEBUG] State: Downloading...
[2026-03-22 21:05:50,292][tftpy.TftpStates][DEBUG] Received OACK from server
[2026-03-22 21:05:50,292][tftpy.TftpStates][DEBUG] Successful negotiation of options
[2026-03-22 21:05:50,292][tftpy.TftpStates][DEBUG]     blksize = 1280
[2026-03-22 21:05:50,292][utils.updater][DEBUG] Successfully uploaded block 1/348
[2026-03-22 21:05:50,292][utils.updater][DEBUG] Unlock the flash protection of bldc driver for OTA
[2026-03-22 21:05:50,293][utils.updater][DEBUG] Received data packet op=3, block=1, len=1284
[2026-03-22 21:05:50,398][utils.updater][DEBUG] Successfully uploaded block 1/348
[2026-03-22 21:05:50,398][utils.updater][DEBUG] Successfully uploaded block 2/348
[2026-03-22 21:05:50,399][utils.updater][DEBUG] Received data packet op=3, block=2, len=1284
[2026-03-22 21:05:50,504][utils.updater][DEBUG] Successfully uploaded block 2/348
[2026-03-22 21:05:50,504][utils.updater][DEBUG] Successfully uploaded block 3/348
[2026-03-22 21:05:50,505][utils.updater][DEBUG] Received data packet op=3, block=3, len=1284
[2026-03-22 21:05:50,610][utils.updater][DEBUG] Successfully uploaded block 3/348
[2026-03-22 21:05:50,610][utils.updater][DEBUG] Successfully uploaded block 4/348
[2026-03-22 21:05:50,611][utils.updater][DEBUG] Received data packet op=3, block=4, len=1284
[2026-03-22 21:05:50,716][utils.updater][DEBUG] Successfully uploaded block 4/348
[2026-03-22 21:05:50,716][utils.updater][DEBUG] Successfully uploaded block 5/348
[2026-03-22 21:05:50,717][utils.updater][DEBUG] Received data packet op=3, block=5, len=1284
[2026-03-22 21:05:50,822][utils.updater][DEBUG] Successfully uploaded block 5/348
[2026-03-22 21:05:50,822][utils.updater][DEBUG] Successfully uploaded block 6/348
[2026-03-22 21:05:50,823][utils.updater][DEBUG] Received data packet op=3, block=6, len=1284
[2026-03-22 21:05:50,928][utils.updater][DEBUG] Successfully uploaded block 6/348
[2026-03-22 21:05:50,928][utils.updater][DEBUG] Successfully uploaded block 7/348
[2026-03-22 21:05:50,929][utils.updater][DEBUG] Received data packet op=3, block=7, len=1284
[2026-03-22 21:05:51,033][utils.updater][DEBUG] Successfully uploaded block 7/348
[2026-03-22 21:05:51,033][utils.updater][DEBUG] Successfully uploaded block 8/348
[2026-03-22 21:05:51,034][utils.updater][DEBUG] Received data packet op=3, block=8, len=1284
[2026-03-22 21:05:51,138][utils.updater][DEBUG] Successfully uploaded block 8/348
[2026-03-22 21:05:51,138][utils.updater][DEBUG] Successfully uploaded block 9/348
[2026-03-22 21:05:51,139][utils.updater][DEBUG] Received data packet op=3, block=9, len=1284
[2026-03-22 21:05:51,244][utils.updater][DEBUG] Successfully uploaded block 9/348
[2026-03-22 21:05:51,244][utils.updater][DEBUG] Successfully uploaded block 10/348
[2026-03-22 21:05:51,245][utils.updater][DEBUG] Received data packet op=3, block=10, len=1284
[2026-03-22 21:05:51,350][utils.updater][DEBUG] Successfully uploaded block 10/348
[2026-03-22 21:05:51,350][utils.updater][DEBUG] Successfully uploaded block 11/348
[2026-03-22 21:05:51,351][utils.updater][DEBUG] Received data packet op=3, block=11, len=1284
[2026-03-22 21:05:51,456][utils.updater][DEBUG] Successfully uploaded block 11/348
[2026-03-22 21:05:51,456][utils.updater][DEBUG] Successfully uploaded block 12/348
[2026-03-22 21:05:51,457][utils.updater][DEBUG] Received data packet op=3, block=12, len=1284
[2026-03-22 21:05:51,561][utils.updater][DEBUG] Successfully uploaded block 12/348
[2026-03-22 21:05:51,561][utils.updater][DEBUG] Successfully uploaded block 13/348
[2026-03-22 21:05:51,562][utils.updater][DEBUG] Received data packet op=3, block=13, len=1284
[2026-03-22 21:05:51,666][utils.updater][DEBUG] Successfully uploaded block 13/348
[2026-03-22 21:05:51,666][utils.updater][DEBUG] Successfully uploaded block 14/348
[2026-03-22 21:05:51,667][utils.updater][DEBUG] Received data packet op=3, block=14, len=1284
[2026-03-22 21:05:51,771][utils.updater][DEBUG] Successfully uploaded block 14/348
[2026-03-22 21:05:51,771][utils.updater][DEBUG] Successfully uploaded block 15/348
[2026-03-22 21:05:51,772][utils.updater][DEBUG] Received data packet op=3, block=15, len=1284
[2026-03-22 21:05:51,876][utils.updater][DEBUG] Successfully uploaded block 15/348
[2026-03-22 21:05:51,876][utils.updater][DEBUG] Successfully uploaded block 16/348
[2026-03-22 21:05:51,877][utils.updater][DEBUG] Received data packet op=3, block=16, len=1284
[2026-03-22 21:05:51,981][utils.updater][DEBUG] Successfully uploaded block 16/348
[2026-03-22 21:05:51,981][utils.updater][DEBUG] Successfully uploaded block 17/348
[2026-03-22 21:05:51,982][utils.updater][DEBUG] Received data packet op=3, block=17, len=1284
[2026-03-22 21:05:52,086][utils.updater][DEBUG] Successfully uploaded block 17/348
[2026-03-22 21:05:52,086][utils.updater][DEBUG] Successfully uploaded block 18/348
[2026-03-22 21:05:52,087][utils.updater][DEBUG] Received data packet op=3, block=18, len=1284
[2026-03-22 21:05:52,192][utils.updater][DEBUG] Successfully uploaded block 18/348
[2026-03-22 21:05:52,192][utils.updater][DEBUG] Successfully uploaded block 19/348
[2026-03-22 21:05:52,193][utils.updater][DEBUG] Received data packet op=3, block=19, len=1284
[2026-03-22 21:05:52,298][utils.updater][DEBUG] Successfully uploaded block 19/348
[2026-03-22 21:05:52,298][utils.updater][DEBUG] Successfully uploaded block 20/348
[2026-03-22 21:05:52,299][utils.updater][DEBUG] Received data packet op=3, block=20, len=1284
[2026-03-22 21:05:52,404][utils.updater][DEBUG] Successfully uploaded block 20/348
[2026-03-22 21:05:52,404][utils.updater][DEBUG] Successfully uploaded block 21/348
[2026-03-22 21:05:52,405][utils.updater][DEBUG] Received data packet op=3, block=21, len=1284
[2026-03-22 21:05:52,509][utils.updater][DEBUG] Successfully uploaded block 21/348
[2026-03-22 21:05:52,509][utils.updater][DEBUG] Successfully uploaded block 22/348
[2026-03-22 21:05:52,510][utils.updater][DEBUG] Received data packet op=3, block=22, len=1284
[2026-03-22 21:05:52,615][utils.updater][DEBUG] Successfully uploaded block 22/348
[2026-03-22 21:05:52,615][utils.updater][DEBUG] Successfully uploaded block 23/348
[2026-03-22 21:05:52,616][utils.updater][DEBUG] Received data packet op=3, block=23, len=1284
[2026-03-22 21:05:52,721][utils.updater][DEBUG] Successfully uploaded block 23/348
[2026-03-22 21:05:52,721][utils.updater][DEBUG] Successfully uploaded block 24/348
[2026-03-22 21:05:52,722][utils.updater][DEBUG] Received data packet op=3, block=24, len=1284
[2026-03-22 21:05:52,826][utils.updater][DEBUG] Successfully uploaded block 24/348
[2026-03-22 21:05:52,826][utils.updater][DEBUG] Successfully uploaded block 25/348
[2026-03-22 21:05:52,827][utils.updater][DEBUG] Received data packet op=3, block=25, len=1284
[2026-03-22 21:05:52,931][utils.updater][DEBUG] Successfully uploaded block 25/348
[2026-03-22 21:05:52,931][utils.updater][DEBUG] Successfully uploaded block 26/348
[2026-03-22 21:05:52,932][utils.updater][DEBUG] Received data packet op=3, block=26, len=1284
[2026-03-22 21:05:53,036][utils.updater][DEBUG] Successfully uploaded block 26/348
[2026-03-22 21:05:53,036][utils.updater][DEBUG] Successfully uploaded block 27/348
[2026-03-22 21:05:53,037][utils.updater][DEBUG] Received data packet op=3, block=27, len=1284
[2026-03-22 21:05:53,141][utils.updater][DEBUG] Successfully uploaded block 27/348
[2026-03-22 21:05:53,141][utils.updater][DEBUG] Successfully uploaded block 28/348
[2026-03-22 21:05:53,142][utils.updater][DEBUG] Received data packet op=3, block=28, len=1284
[2026-03-22 21:05:53,247][utils.updater][DEBUG] Successfully uploaded block 28/348
[2026-03-22 21:05:53,247][utils.updater][DEBUG] Successfully uploaded block 29/348
[2026-03-22 21:05:53,248][utils.updater][DEBUG] Received data packet op=3, block=29, len=1284
[2026-03-22 21:05:53,352][utils.updater][DEBUG] Successfully uploaded block 29/348
[2026-03-22 21:05:53,352][utils.updater][DEBUG] Successfully uploaded block 30/348
[2026-03-22 21:05:53,353][utils.updater][DEBUG] Received data packet op=3, block=30, len=1284
[2026-03-22 21:05:53,457][utils.updater][DEBUG] Successfully uploaded block 30/348
[2026-03-22 21:05:53,457][utils.updater][DEBUG] Successfully uploaded block 31/348
[2026-03-22 21:05:53,458][utils.updater][DEBUG] Received data packet op=3, block=31, len=1284
[2026-03-22 21:05:53,563][utils.updater][DEBUG] Successfully uploaded block 31/348
[2026-03-22 21:05:53,563][utils.updater][DEBUG] Successfully uploaded block 32/348
[2026-03-22 21:05:53,564][utils.updater][DEBUG] Received data packet op=3, block=32, len=1284
[2026-03-22 21:05:53,669][utils.updater][DEBUG] Successfully uploaded block 32/348
[2026-03-22 21:05:53,669][utils.updater][DEBUG] Successfully uploaded block 33/348
[2026-03-22 21:05:53,670][utils.updater][DEBUG] Received data packet op=3, block=33, len=1284
[2026-03-22 21:05:53,774][utils.updater][DEBUG] Successfully uploaded block 33/348
[2026-03-22 21:05:53,774][utils.updater][DEBUG] Successfully uploaded block 34/348
[2026-03-22 21:05:53,775][utils.updater][DEBUG] Received data packet op=3, block=34, len=1284
[2026-03-22 21:05:53,879][utils.updater][DEBUG] Successfully uploaded block 34/348
[2026-03-22 21:05:53,879][utils.updater][DEBUG] Successfully uploaded block 35/348
[2026-03-22 21:05:53,880][utils.updater][DEBUG] Received data packet op=3, block=35, len=1284
[2026-03-22 21:05:53,984][utils.updater][DEBUG] Successfully uploaded block 35/348
[2026-03-22 21:05:53,984][utils.updater][DEBUG] Successfully uploaded block 36/348
[2026-03-22 21:05:53,985][utils.updater][DEBUG] Received data packet op=3, block=36, len=1284
[2026-03-22 21:05:54,090][utils.updater][DEBUG] Successfully uploaded block 36/348
[2026-03-22 21:05:54,090][utils.updater][DEBUG] Successfully uploaded block 37/348
[2026-03-22 21:05:54,091][utils.updater][DEBUG] Received data packet op=3, block=37, len=1284
[2026-03-22 21:05:54,195][utils.updater][DEBUG] Successfully uploaded block 37/348
[2026-03-22 21:05:54,195][utils.updater][DEBUG] Successfully uploaded block 38/348
[2026-03-22 21:05:54,196][utils.updater][DEBUG] Received data packet op=3, block=38, len=1284
[2026-03-22 21:05:54,300][utils.updater][DEBUG] Successfully uploaded block 38/348
[2026-03-22 21:05:54,300][utils.updater][DEBUG] Successfully uploaded block 39/348
[2026-03-22 21:05:54,301][utils.updater][DEBUG] Received data packet op=3, block=39, len=1284
[2026-03-22 21:05:54,405][utils.updater][DEBUG] Successfully uploaded block 39/348
[2026-03-22 21:05:54,405][utils.updater][DEBUG] Successfully uploaded block 40/348
[2026-03-22 21:05:54,406][utils.updater][DEBUG] Received data packet op=3, block=40, len=1284
[2026-03-22 21:05:54,510][utils.updater][DEBUG] Successfully uploaded block 40/348
[2026-03-22 21:05:54,510][utils.updater][DEBUG] Successfully uploaded block 41/348
[2026-03-22 21:05:54,511][utils.updater][DEBUG] Received data packet op=3, block=41, len=1284
[2026-03-22 21:05:54,615][utils.updater][DEBUG] Successfully uploaded block 41/348
[2026-03-22 21:05:54,615][utils.updater][DEBUG] Successfully uploaded block 42/348
[2026-03-22 21:05:54,616][utils.updater][DEBUG] Received data packet op=3, block=42, len=1284
[2026-03-22 21:05:54,720][utils.updater][DEBUG] Successfully uploaded block 42/348
[2026-03-22 21:05:54,720][utils.updater][DEBUG] Successfully uploaded block 43/348
[2026-03-22 21:05:54,721][utils.updater][DEBUG] Received data packet op=3, block=43, len=1284
[2026-03-22 21:05:54,825][utils.updater][DEBUG] Successfully uploaded block 43/348
[2026-03-22 21:05:54,825][utils.updater][DEBUG] Successfully uploaded block 44/348
[2026-03-22 21:05:54,826][utils.updater][DEBUG] Received data packet op=3, block=44, len=1284
[2026-03-22 21:05:54,931][utils.updater][DEBUG] Successfully uploaded block 44/348
[2026-03-22 21:05:54,931][utils.updater][DEBUG] Successfully uploaded block 45/348
[2026-03-22 21:05:54,932][utils.updater][DEBUG] Received data packet op=3, block=45, len=1284
[2026-03-22 21:05:55,037][utils.updater][DEBUG] Successfully uploaded block 45/348
[2026-03-22 21:05:55,037][utils.updater][DEBUG] Successfully uploaded block 46/348
[2026-03-22 21:05:55,038][utils.updater][DEBUG] Received data packet op=3, block=46, len=1284
[2026-03-22 21:05:55,142][utils.updater][DEBUG] Successfully uploaded block 46/348
[2026-03-22 21:05:55,142][utils.updater][DEBUG] Successfully uploaded block 47/348
[2026-03-22 21:05:55,143][utils.updater][DEBUG] Received data packet op=3, block=47, len=1284
[2026-03-22 21:05:55,247][utils.updater][DEBUG] Successfully uploaded block 47/348
[2026-03-22 21:05:55,247][utils.updater][DEBUG] Successfully uploaded block 48/348
[2026-03-22 21:05:55,248][utils.updater][DEBUG] Received data packet op=3, block=48, len=1284
[2026-03-22 21:05:55,352][utils.updater][DEBUG] Successfully uploaded block 48/348
[2026-03-22 21:05:55,352][utils.updater][DEBUG] Successfully uploaded block 49/348
[2026-03-22 21:05:55,353][utils.updater][DEBUG] Received data packet op=3, block=49, len=1284
[2026-03-22 21:05:55,457][utils.updater][DEBUG] Successfully uploaded block 49/348
[2026-03-22 21:05:55,457][utils.updater][DEBUG] Successfully uploaded block 50/348
[2026-03-22 21:05:55,458][utils.updater][DEBUG] Received data packet op=3, block=50, len=1284
[2026-03-22 21:05:55,562][utils.updater][DEBUG] Successfully uploaded block 50/348
[2026-03-22 21:05:55,562][utils.updater][DEBUG] Successfully uploaded block 51/348
[2026-03-22 21:05:55,563][utils.updater][DEBUG] Received data packet op=3, block=51, len=1284
[2026-03-22 21:05:55,667][utils.updater][DEBUG] Successfully uploaded block 51/348
[2026-03-22 21:05:55,667][utils.updater][DEBUG] Successfully uploaded block 52/348
[2026-03-22 21:05:55,668][utils.updater][DEBUG] Received data packet op=3, block=52, len=1284
[2026-03-22 21:05:55,772][utils.updater][DEBUG] Successfully uploaded block 52/348
[2026-03-22 21:05:55,772][utils.updater][DEBUG] Successfully uploaded block 53/348
[2026-03-22 21:05:55,773][utils.updater][DEBUG] Received data packet op=3, block=53, len=1284
[2026-03-22 21:05:55,878][utils.updater][DEBUG] Successfully uploaded block 53/348
[2026-03-22 21:05:55,878][utils.updater][DEBUG] Successfully uploaded block 54/348
[2026-03-22 21:05:55,879][utils.updater][DEBUG] Received data packet op=3, block=54, len=1284
[2026-03-22 21:05:55,983][utils.updater][DEBUG] Successfully uploaded block 54/348
[2026-03-22 21:05:55,983][utils.updater][DEBUG] Successfully uploaded block 55/348
[2026-03-22 21:05:55,984][utils.updater][DEBUG] Received data packet op=3, block=55, len=1284
[2026-03-22 21:05:56,089][utils.updater][DEBUG] Successfully uploaded block 55/348
[2026-03-22 21:05:56,089][utils.updater][DEBUG] Successfully uploaded block 56/348
[2026-03-22 21:05:56,090][utils.updater][DEBUG] Received data packet op=3, block=56, len=1284
[2026-03-22 21:05:56,195][utils.updater][DEBUG] Successfully uploaded block 56/348
[2026-03-22 21:05:56,195][utils.updater][DEBUG] Successfully uploaded block 57/348
[2026-03-22 21:05:56,196][utils.updater][DEBUG] Received data packet op=3, block=57, len=1284
[2026-03-22 21:05:56,300][utils.updater][DEBUG] Successfully uploaded block 57/348
[2026-03-22 21:05:56,300][utils.updater][DEBUG] Successfully uploaded block 58/348
[2026-03-22 21:05:56,301][utils.updater][DEBUG] Received data packet op=3, block=58, len=1284
[2026-03-22 21:05:56,405][utils.updater][DEBUG] Successfully uploaded block 58/348
[2026-03-22 21:05:56,405][utils.updater][DEBUG] Successfully uploaded block 59/348
[2026-03-22 21:05:56,406][utils.updater][DEBUG] Received data packet op=3, block=59, len=1284
[2026-03-22 21:05:56,510][utils.updater][DEBUG] Successfully uploaded block 59/348
[2026-03-22 21:05:56,510][utils.updater][DEBUG] Successfully uploaded block 60/348
[2026-03-22 21:05:56,511][utils.updater][DEBUG] Received data packet op=3, block=60, len=1284
[2026-03-22 21:05:56,615][utils.updater][DEBUG] Successfully uploaded block 60/348
[2026-03-22 21:05:56,615][utils.updater][DEBUG] Successfully uploaded block 61/348
[2026-03-22 21:05:56,616][utils.updater][DEBUG] Received data packet op=3, block=61, len=1284
[2026-03-22 21:05:56,720][utils.updater][DEBUG] Successfully uploaded block 61/348
[2026-03-22 21:05:56,720][utils.updater][DEBUG] Successfully uploaded block 62/348
[2026-03-22 21:05:56,721][utils.updater][DEBUG] Received data packet op=3, block=62, len=1284
[2026-03-22 21:05:56,825][utils.updater][DEBUG] Successfully uploaded block 62/348
[2026-03-22 21:05:56,825][utils.updater][DEBUG] Successfully uploaded block 63/348
[2026-03-22 21:05:56,826][utils.updater][DEBUG] Received data packet op=3, block=63, len=1284
[2026-03-22 21:05:56,933][utils.updater][DEBUG] Successfully uploaded block 63/348
[2026-03-22 21:05:56,933][utils.updater][DEBUG] Successfully uploaded block 64/348
[2026-03-22 21:05:56,934][utils.updater][DEBUG] Received data packet op=3, block=64, len=1284
[2026-03-22 21:05:57,041][utils.updater][DEBUG] Successfully uploaded block 64/348
[2026-03-22 21:05:57,041][utils.updater][DEBUG] Successfully uploaded block 65/348
[2026-03-22 21:05:57,042][utils.updater][DEBUG] Received data packet op=3, block=65, len=1284
[2026-03-22 21:05:57,149][utils.updater][DEBUG] Successfully uploaded block 65/348
[2026-03-22 21:05:57,149][utils.updater][DEBUG] Successfully uploaded block 66/348
[2026-03-22 21:05:57,150][utils.updater][DEBUG] Received data packet op=3, block=66, len=1284
[2026-03-22 21:05:57,257][utils.updater][DEBUG] Successfully uploaded block 66/348
[2026-03-22 21:05:57,257][utils.updater][DEBUG] Successfully uploaded block 67/348
[2026-03-22 21:05:57,258][utils.updater][DEBUG] Received data packet op=3, block=67, len=1284
[2026-03-22 21:05:57,365][utils.updater][DEBUG] Successfully uploaded block 67/348
[2026-03-22 21:05:57,365][utils.updater][DEBUG] Successfully uploaded block 68/348
[2026-03-22 21:05:57,366][utils.updater][DEBUG] Received data packet op=3, block=68, len=1284
[2026-03-22 21:05:57,473][utils.updater][DEBUG] Successfully uploaded block 68/348
[2026-03-22 21:05:57,473][utils.updater][DEBUG] Successfully uploaded block 69/348
[2026-03-22 21:05:57,474][utils.updater][DEBUG] Received data packet op=3, block=69, len=1284
[2026-03-22 21:05:57,581][utils.updater][DEBUG] Successfully uploaded block 69/348
[2026-03-22 21:05:57,581][utils.updater][DEBUG] Successfully uploaded block 70/348
[2026-03-22 21:05:57,582][utils.updater][DEBUG] Received data packet op=3, block=70, len=1284
[2026-03-22 21:05:57,689][utils.updater][DEBUG] Successfully uploaded block 70/348
[2026-03-22 21:05:57,689][utils.updater][DEBUG] Successfully uploaded block 71/348
[2026-03-22 21:05:57,690][utils.updater][DEBUG] Received data packet op=3, block=71, len=1284
[2026-03-22 21:05:57,797][utils.updater][DEBUG] Successfully uploaded block 71/348
[2026-03-22 21:05:57,797][utils.updater][DEBUG] Successfully uploaded block 72/348
[2026-03-22 21:05:57,798][utils.updater][DEBUG] Received data packet op=3, block=72, len=1284
[2026-03-22 21:05:57,905][utils.updater][DEBUG] Successfully uploaded block 72/348
[2026-03-22 21:05:57,905][utils.updater][DEBUG] Successfully uploaded block 73/348
[2026-03-22 21:05:57,906][utils.updater][DEBUG] Received data packet op=3, block=73, len=1284
[2026-03-22 21:05:58,013][utils.updater][DEBUG] Successfully uploaded block 73/348
[2026-03-22 21:05:58,013][utils.updater][DEBUG] Successfully uploaded block 74/348
[2026-03-22 21:05:58,014][utils.updater][DEBUG] Received data packet op=3, block=74, len=1284
[2026-03-22 21:05:58,121][utils.updater][DEBUG] Successfully uploaded block 74/348
[2026-03-22 21:05:58,121][utils.updater][DEBUG] Successfully uploaded block 75/348
[2026-03-22 21:05:58,122][utils.updater][DEBUG] Received data packet op=3, block=75, len=1284
[2026-03-22 21:05:58,229][utils.updater][DEBUG] Successfully uploaded block 75/348
[2026-03-22 21:05:58,229][utils.updater][DEBUG] Successfully uploaded block 76/348
[2026-03-22 21:05:58,230][utils.updater][DEBUG] Received data packet op=3, block=76, len=1284
[2026-03-22 21:05:58,337][utils.updater][DEBUG] Successfully uploaded block 76/348
[2026-03-22 21:05:58,337][utils.updater][DEBUG] Successfully uploaded block 77/348
[2026-03-22 21:05:58,338][utils.updater][DEBUG] Received data packet op=3, block=77, len=1284
[2026-03-22 21:05:58,445][utils.updater][DEBUG] Successfully uploaded block 77/348
[2026-03-22 21:05:58,445][utils.updater][DEBUG] Successfully uploaded block 78/348
[2026-03-22 21:05:58,446][utils.updater][DEBUG] Received data packet op=3, block=78, len=1284
[2026-03-22 21:05:58,553][utils.updater][DEBUG] Successfully uploaded block 78/348
[2026-03-22 21:05:58,553][utils.updater][DEBUG] Successfully uploaded block 79/348
[2026-03-22 21:05:58,554][utils.updater][DEBUG] Received data packet op=3, block=79, len=1284
[2026-03-22 21:05:58,661][utils.updater][DEBUG] Successfully uploaded block 79/348
[2026-03-22 21:05:58,661][utils.updater][DEBUG] Successfully uploaded block 80/348
[2026-03-22 21:05:58,662][utils.updater][DEBUG] Received data packet op=3, block=80, len=1284
[2026-03-22 21:05:58,769][utils.updater][DEBUG] Successfully uploaded block 80/348
[2026-03-22 21:05:58,769][utils.updater][DEBUG] Successfully uploaded block 81/348
[2026-03-22 21:05:58,770][utils.updater][DEBUG] Received data packet op=3, block=81, len=1284
[2026-03-22 21:05:58,877][utils.updater][DEBUG] Successfully uploaded block 81/348
[2026-03-22 21:05:58,877][utils.updater][DEBUG] Successfully uploaded block 82/348
[2026-03-22 21:05:58,878][utils.updater][DEBUG] Received data packet op=3, block=82, len=1284
[2026-03-22 21:05:58,985][utils.updater][DEBUG] Successfully uploaded block 82/348
[2026-03-22 21:05:58,985][utils.updater][DEBUG] Successfully uploaded block 83/348
[2026-03-22 21:05:58,986][utils.updater][DEBUG] Received data packet op=3, block=83, len=1284
[2026-03-22 21:05:59,093][utils.updater][DEBUG] Successfully uploaded block 83/348
[2026-03-22 21:05:59,093][utils.updater][DEBUG] Successfully uploaded block 84/348
[2026-03-22 21:05:59,094][utils.updater][DEBUG] Received data packet op=3, block=84, len=1284
[2026-03-22 21:05:59,201][utils.updater][DEBUG] Successfully uploaded block 84/348
[2026-03-22 21:05:59,201][utils.updater][DEBUG] Successfully uploaded block 85/348
[2026-03-22 21:05:59,202][utils.updater][DEBUG] Received data packet op=3, block=85, len=1284
[2026-03-22 21:05:59,309][utils.updater][DEBUG] Successfully uploaded block 85/348
[2026-03-22 21:05:59,309][utils.updater][DEBUG] Successfully uploaded block 86/348
[2026-03-22 21:05:59,310][utils.updater][DEBUG] Received data packet op=3, block=86, len=1284
[2026-03-22 21:05:59,417][utils.updater][DEBUG] Successfully uploaded block 86/348
[2026-03-22 21:05:59,417][utils.updater][DEBUG] Successfully uploaded block 87/348
[2026-03-22 21:05:59,418][utils.updater][DEBUG] Received data packet op=3, block=87, len=1284
[2026-03-22 21:05:59,525][utils.updater][DEBUG] Successfully uploaded block 87/348
[2026-03-22 21:05:59,525][utils.updater][DEBUG] Successfully uploaded block 88/348
[2026-03-22 21:05:59,526][utils.updater][DEBUG] Received data packet op=3, block=88, len=1284
[2026-03-22 21:05:59,633][utils.updater][DEBUG] Successfully uploaded block 88/348
[2026-03-22 21:05:59,633][utils.updater][DEBUG] Successfully uploaded block 89/348
[2026-03-22 21:05:59,634][utils.updater][DEBUG] Received data packet op=3, block=89, len=1284
[2026-03-22 21:05:59,741][utils.updater][DEBUG] Successfully uploaded block 89/348
[2026-03-22 21:05:59,741][utils.updater][DEBUG] Successfully uploaded block 90/348
[2026-03-22 21:05:59,742][utils.updater][DEBUG] Received data packet op=3, block=90, len=1284
[2026-03-22 21:05:59,849][utils.updater][DEBUG] Successfully uploaded block 90/348
[2026-03-22 21:05:59,849][utils.updater][DEBUG] Successfully uploaded block 91/348
[2026-03-22 21:05:59,850][utils.updater][DEBUG] Received data packet op=3, block=91, len=1284
[2026-03-22 21:05:59,957][utils.updater][DEBUG] Successfully uploaded block 91/348
[2026-03-22 21:05:59,957][utils.updater][DEBUG] Successfully uploaded block 92/348
[2026-03-22 21:05:59,958][utils.updater][DEBUG] Received data packet op=3, block=92, len=1284
[2026-03-22 21:06:00,065][utils.updater][DEBUG] Successfully uploaded block 92/348
[2026-03-22 21:06:00,065][utils.updater][DEBUG] Successfully uploaded block 93/348
[2026-03-22 21:06:00,066][utils.updater][DEBUG] Received data packet op=3, block=93, len=1284
[2026-03-22 21:06:00,173][utils.updater][DEBUG] Successfully uploaded block 93/348
[2026-03-22 21:06:00,173][utils.updater][DEBUG] Successfully uploaded block 94/348
[2026-03-22 21:06:00,174][utils.updater][DEBUG] Received data packet op=3, block=94, len=1284
[2026-03-22 21:06:00,281][utils.updater][DEBUG] Successfully uploaded block 94/348
[2026-03-22 21:06:00,281][utils.updater][DEBUG] Successfully uploaded block 95/348
[2026-03-22 21:06:00,282][utils.updater][DEBUG] Received data packet op=3, block=95, len=1284
[2026-03-22 21:06:00,389][utils.updater][DEBUG] Successfully uploaded block 95/348
[2026-03-22 21:06:00,389][utils.updater][DEBUG] Successfully uploaded block 96/348
[2026-03-22 21:06:00,390][utils.updater][DEBUG] Received data packet op=3, block=96, len=1284
[2026-03-22 21:06:00,497][utils.updater][DEBUG] Successfully uploaded block 96/348
[2026-03-22 21:06:00,497][utils.updater][DEBUG] Successfully uploaded block 97/348
[2026-03-22 21:06:00,498][utils.updater][DEBUG] Received data packet op=3, block=97, len=1284
[2026-03-22 21:06:00,605][utils.updater][DEBUG] Successfully uploaded block 97/348
[2026-03-22 21:06:00,605][utils.updater][DEBUG] Successfully uploaded block 98/348
[2026-03-22 21:06:00,606][utils.updater][DEBUG] Received data packet op=3, block=98, len=1284
[2026-03-22 21:06:00,713][utils.updater][DEBUG] Successfully uploaded block 98/348
[2026-03-22 21:06:00,713][utils.updater][DEBUG] Successfully uploaded block 99/348
[2026-03-22 21:06:00,714][utils.updater][DEBUG] Received data packet op=3, block=99, len=1284
[2026-03-22 21:06:00,821][utils.updater][DEBUG] Successfully uploaded block 99/348
[2026-03-22 21:06:00,821][utils.updater][DEBUG] Successfully uploaded block 100/348
[2026-03-22 21:06:00,822][utils.updater][DEBUG] Received data packet op=3, block=100, len=1284
[2026-03-22 21:06:00,929][utils.updater][DEBUG] Successfully uploaded block 100/348
[2026-03-22 21:06:00,929][utils.updater][DEBUG] Successfully uploaded block 101/348
[2026-03-22 21:06:00,930][utils.updater][DEBUG] Received data packet op=3, block=101, len=1284
[2026-03-22 21:06:01,037][utils.updater][DEBUG] Successfully uploaded block 101/348
[2026-03-22 21:06:01,037][utils.updater][DEBUG] Successfully uploaded block 102/348
[2026-03-22 21:06:01,038][utils.updater][DEBUG] Received data packet op=3, block=102, len=1284
[2026-03-22 21:06:01,147][utils.updater][DEBUG] Successfully uploaded block 102/348
[2026-03-22 21:06:01,147][utils.updater][DEBUG] Successfully uploaded block 103/348
[2026-03-22 21:06:01,148][utils.updater][DEBUG] Received data packet op=3, block=103, len=1284
[2026-03-22 21:06:01,255][utils.updater][DEBUG] Successfully uploaded block 103/348
[2026-03-22 21:06:01,255][utils.updater][DEBUG] Successfully uploaded block 104/348
[2026-03-22 21:06:01,256][utils.updater][DEBUG] Received data packet op=3, block=104, len=1284
[2026-03-22 21:06:01,363][utils.updater][DEBUG] Successfully uploaded block 104/348
[2026-03-22 21:06:01,363][utils.updater][DEBUG] Successfully uploaded block 105/348
[2026-03-22 21:06:01,364][utils.updater][DEBUG] Received data packet op=3, block=105, len=1284
[2026-03-22 21:06:01,471][utils.updater][DEBUG] Successfully uploaded block 105/348
[2026-03-22 21:06:01,471][utils.updater][DEBUG] Successfully uploaded block 106/348
[2026-03-22 21:06:01,472][utils.updater][DEBUG] Received data packet op=3, block=106, len=1284
[2026-03-22 21:06:01,579][utils.updater][DEBUG] Successfully uploaded block 106/348
[2026-03-22 21:06:01,579][utils.updater][DEBUG] Successfully uploaded block 107/348
[2026-03-22 21:06:01,580][utils.updater][DEBUG] Received data packet op=3, block=107, len=1284
[2026-03-22 21:06:01,687][utils.updater][DEBUG] Successfully uploaded block 107/348
[2026-03-22 21:06:01,687][utils.updater][DEBUG] Successfully uploaded block 108/348
[2026-03-22 21:06:01,688][utils.updater][DEBUG] Received data packet op=3, block=108, len=1284
[2026-03-22 21:06:01,795][utils.updater][DEBUG] Successfully uploaded block 108/348
[2026-03-22 21:06:01,795][utils.updater][DEBUG] Successfully uploaded block 109/348
[2026-03-22 21:06:01,796][utils.updater][DEBUG] Received data packet op=3, block=109, len=1284
[2026-03-22 21:06:01,903][utils.updater][DEBUG] Successfully uploaded block 109/348
[2026-03-22 21:06:01,903][utils.updater][DEBUG] Successfully uploaded block 110/348
[2026-03-22 21:06:01,904][utils.updater][DEBUG] Received data packet op=3, block=110, len=1284
[2026-03-22 21:06:02,011][utils.updater][DEBUG] Successfully uploaded block 110/348
[2026-03-22 21:06:02,011][utils.updater][DEBUG] Successfully uploaded block 111/348
[2026-03-22 21:06:02,012][utils.updater][DEBUG] Received data packet op=3, block=111, len=1284
[2026-03-22 21:06:02,116][utils.updater][DEBUG] Successfully uploaded block 111/348
[2026-03-22 21:06:02,116][utils.updater][DEBUG] Successfully uploaded block 112/348
[2026-03-22 21:06:02,117][utils.updater][DEBUG] Received data packet op=3, block=112, len=1284
[2026-03-22 21:06:02,221][utils.updater][DEBUG] Successfully uploaded block 112/348
[2026-03-22 21:06:02,221][utils.updater][DEBUG] Successfully uploaded block 113/348
[2026-03-22 21:06:02,222][utils.updater][DEBUG] Received data packet op=3, block=113, len=1284
[2026-03-22 21:06:02,326][utils.updater][DEBUG] Successfully uploaded block 113/348
[2026-03-22 21:06:02,326][utils.updater][DEBUG] Successfully uploaded block 114/348
[2026-03-22 21:06:02,327][utils.updater][DEBUG] Received data packet op=3, block=114, len=1284
[2026-03-22 21:06:02,431][utils.updater][DEBUG] Successfully uploaded block 114/348
[2026-03-22 21:06:02,431][utils.updater][DEBUG] Successfully uploaded block 115/348
[2026-03-22 21:06:02,432][utils.updater][DEBUG] Received data packet op=3, block=115, len=1284
[2026-03-22 21:06:02,536][utils.updater][DEBUG] Successfully uploaded block 115/348
[2026-03-22 21:06:02,536][utils.updater][DEBUG] Successfully uploaded block 116/348
[2026-03-22 21:06:02,537][utils.updater][DEBUG] Received data packet op=3, block=116, len=1284
[2026-03-22 21:06:02,641][utils.updater][DEBUG] Successfully uploaded block 116/348
[2026-03-22 21:06:02,641][utils.updater][DEBUG] Successfully uploaded block 117/348
[2026-03-22 21:06:02,642][utils.updater][DEBUG] Received data packet op=3, block=117, len=1284
[2026-03-22 21:06:02,746][utils.updater][DEBUG] Successfully uploaded block 117/348
[2026-03-22 21:06:02,746][utils.updater][DEBUG] Successfully uploaded block 118/348
[2026-03-22 21:06:02,747][utils.updater][DEBUG] Received data packet op=3, block=118, len=1284
[2026-03-22 21:06:02,851][utils.updater][DEBUG] Successfully uploaded block 118/348
[2026-03-22 21:06:02,851][utils.updater][DEBUG] Successfully uploaded block 119/348
[2026-03-22 21:06:02,852][utils.updater][DEBUG] Received data packet op=3, block=119, len=1284
[2026-03-22 21:06:02,957][utils.updater][DEBUG] Successfully uploaded block 119/348
[2026-03-22 21:06:02,957][utils.updater][DEBUG] Successfully uploaded block 120/348
[2026-03-22 21:06:02,958][utils.updater][DEBUG] Received data packet op=3, block=120, len=1284
[2026-03-22 21:06:03,063][utils.updater][DEBUG] Successfully uploaded block 120/348
[2026-03-22 21:06:03,063][utils.updater][DEBUG] Successfully uploaded block 121/348
[2026-03-22 21:06:03,064][utils.updater][DEBUG] Received data packet op=3, block=121, len=1284
[2026-03-22 21:06:03,168][utils.updater][DEBUG] Successfully uploaded block 121/348
[2026-03-22 21:06:03,168][utils.updater][DEBUG] Successfully uploaded block 122/348
[2026-03-22 21:06:03,169][utils.updater][DEBUG] Received data packet op=3, block=122, len=1284
[2026-03-22 21:06:03,274][utils.updater][DEBUG] Successfully uploaded block 122/348
[2026-03-22 21:06:03,274][utils.updater][DEBUG] Successfully uploaded block 123/348
[2026-03-22 21:06:03,275][utils.updater][DEBUG] Received data packet op=3, block=123, len=1284
[2026-03-22 21:06:03,379][utils.updater][DEBUG] Successfully uploaded block 123/348
[2026-03-22 21:06:03,379][utils.updater][DEBUG] Successfully uploaded block 124/348
[2026-03-22 21:06:03,380][utils.updater][DEBUG] Received data packet op=3, block=124, len=1284
[2026-03-22 21:06:03,484][utils.updater][DEBUG] Successfully uploaded block 124/348
[2026-03-22 21:06:03,484][utils.updater][DEBUG] Successfully uploaded block 125/348
[2026-03-22 21:06:03,485][utils.updater][DEBUG] Received data packet op=3, block=125, len=1284
[2026-03-22 21:06:03,589][utils.updater][DEBUG] Successfully uploaded block 125/348
[2026-03-22 21:06:03,589][utils.updater][DEBUG] Successfully uploaded block 126/348
[2026-03-22 21:06:03,590][utils.updater][DEBUG] Received data packet op=3, block=126, len=1284
[2026-03-22 21:06:03,694][utils.updater][DEBUG] Successfully uploaded block 126/348
[2026-03-22 21:06:03,694][utils.updater][DEBUG] Successfully uploaded block 127/348
[2026-03-22 21:06:03,695][utils.updater][DEBUG] Received data packet op=3, block=127, len=1284
[2026-03-22 21:06:03,799][utils.updater][DEBUG] Successfully uploaded block 127/348
[2026-03-22 21:06:03,799][utils.updater][DEBUG] Successfully uploaded block 128/348
[2026-03-22 21:06:03,800][utils.updater][DEBUG] Received data packet op=3, block=128, len=1284
[2026-03-22 21:06:03,904][utils.updater][DEBUG] Successfully uploaded block 128/348
[2026-03-22 21:06:03,904][utils.updater][DEBUG] Successfully uploaded block 129/348
[2026-03-22 21:06:03,905][utils.updater][DEBUG] Received data packet op=3, block=129, len=1284
[2026-03-22 21:06:04,009][utils.updater][DEBUG] Successfully uploaded block 129/348
[2026-03-22 21:06:04,009][utils.updater][DEBUG] Successfully uploaded block 130/348
[2026-03-22 21:06:04,010][utils.updater][DEBUG] Received data packet op=3, block=130, len=1284
[2026-03-22 21:06:04,114][utils.updater][DEBUG] Successfully uploaded block 130/348
[2026-03-22 21:06:04,114][utils.updater][DEBUG] Successfully uploaded block 131/348
[2026-03-22 21:06:04,115][utils.updater][DEBUG] Received data packet op=3, block=131, len=1284
[2026-03-22 21:06:04,219][utils.updater][DEBUG] Successfully uploaded block 131/348
[2026-03-22 21:06:04,219][utils.updater][DEBUG] Successfully uploaded block 132/348
[2026-03-22 21:06:04,220][utils.updater][DEBUG] Received data packet op=3, block=132, len=1284
[2026-03-22 21:06:04,324][utils.updater][DEBUG] Successfully uploaded block 132/348
[2026-03-22 21:06:04,324][utils.updater][DEBUG] Successfully uploaded block 133/348
[2026-03-22 21:06:04,325][utils.updater][DEBUG] Received data packet op=3, block=133, len=1284
[2026-03-22 21:06:04,429][utils.updater][DEBUG] Successfully uploaded block 133/348
[2026-03-22 21:06:04,429][utils.updater][DEBUG] Successfully uploaded block 134/348
[2026-03-22 21:06:04,430][utils.updater][DEBUG] Received data packet op=3, block=134, len=1284
[2026-03-22 21:06:04,534][utils.updater][DEBUG] Successfully uploaded block 134/348
[2026-03-22 21:06:04,534][utils.updater][DEBUG] Successfully uploaded block 135/348
[2026-03-22 21:06:04,535][utils.updater][DEBUG] Received data packet op=3, block=135, len=1284
[2026-03-22 21:06:04,639][utils.updater][DEBUG] Successfully uploaded block 135/348
[2026-03-22 21:06:04,639][utils.updater][DEBUG] Successfully uploaded block 136/348
[2026-03-22 21:06:04,640][utils.updater][DEBUG] Received data packet op=3, block=136, len=1284
[2026-03-22 21:06:04,744][utils.updater][DEBUG] Successfully uploaded block 136/348
[2026-03-22 21:06:04,744][utils.updater][DEBUG] Successfully uploaded block 137/348
[2026-03-22 21:06:04,745][utils.updater][DEBUG] Received data packet op=3, block=137, len=1284
[2026-03-22 21:06:04,849][utils.updater][DEBUG] Successfully uploaded block 137/348
[2026-03-22 21:06:04,849][utils.updater][DEBUG] Successfully uploaded block 138/348
[2026-03-22 21:06:04,850][utils.updater][DEBUG] Received data packet op=3, block=138, len=1284
[2026-03-22 21:06:04,954][utils.updater][DEBUG] Successfully uploaded block 138/348
[2026-03-22 21:06:04,954][utils.updater][DEBUG] Successfully uploaded block 139/348
[2026-03-22 21:06:04,955][utils.updater][DEBUG] Received data packet op=3, block=139, len=1284
[2026-03-22 21:06:05,059][utils.updater][DEBUG] Successfully uploaded block 139/348
[2026-03-22 21:06:05,059][utils.updater][DEBUG] Successfully uploaded block 140/348
[2026-03-22 21:06:05,060][utils.updater][DEBUG] Received data packet op=3, block=140, len=1284
[2026-03-22 21:06:05,164][utils.updater][DEBUG] Successfully uploaded block 140/348
[2026-03-22 21:06:05,164][utils.updater][DEBUG] Successfully uploaded block 141/348
[2026-03-22 21:06:05,165][utils.updater][DEBUG] Received data packet op=3, block=141, len=1284
[2026-03-22 21:06:05,269][utils.updater][DEBUG] Successfully uploaded block 141/348
[2026-03-22 21:06:05,269][utils.updater][DEBUG] Successfully uploaded block 142/348
[2026-03-22 21:06:05,270][utils.updater][DEBUG] Received data packet op=3, block=142, len=1284
[2026-03-22 21:06:05,374][utils.updater][DEBUG] Successfully uploaded block 142/348
[2026-03-22 21:06:05,374][utils.updater][DEBUG] Successfully uploaded block 143/348
[2026-03-22 21:06:05,375][utils.updater][DEBUG] Received data packet op=3, block=143, len=1284
[2026-03-22 21:06:05,479][utils.updater][DEBUG] Successfully uploaded block 143/348
[2026-03-22 21:06:05,479][utils.updater][DEBUG] Successfully uploaded block 144/348
[2026-03-22 21:06:05,480][utils.updater][DEBUG] Received data packet op=3, block=144, len=1284
[2026-03-22 21:06:05,584][utils.updater][DEBUG] Successfully uploaded block 144/348
[2026-03-22 21:06:05,584][utils.updater][DEBUG] Successfully uploaded block 145/348
[2026-03-22 21:06:05,585][utils.updater][DEBUG] Received data packet op=3, block=145, len=1284
[2026-03-22 21:06:05,689][utils.updater][DEBUG] Successfully uploaded block 145/348
[2026-03-22 21:06:05,689][utils.updater][DEBUG] Successfully uploaded block 146/348
[2026-03-22 21:06:05,690][utils.updater][DEBUG] Received data packet op=3, block=146, len=1284
[2026-03-22 21:06:05,794][utils.updater][DEBUG] Successfully uploaded block 146/348
[2026-03-22 21:06:05,794][utils.updater][DEBUG] Successfully uploaded block 147/348
[2026-03-22 21:06:05,795][utils.updater][DEBUG] Received data packet op=3, block=147, len=1284
[2026-03-22 21:06:05,899][utils.updater][DEBUG] Successfully uploaded block 147/348
[2026-03-22 21:06:05,899][utils.updater][DEBUG] Successfully uploaded block 148/348
[2026-03-22 21:06:05,900][utils.updater][DEBUG] Received data packet op=3, block=148, len=1284
[2026-03-22 21:06:06,004][utils.updater][DEBUG] Successfully uploaded block 148/348
[2026-03-22 21:06:06,004][utils.updater][DEBUG] Successfully uploaded block 149/348
[2026-03-22 21:06:06,005][utils.updater][DEBUG] Received data packet op=3, block=149, len=1284
[2026-03-22 21:06:06,109][utils.updater][DEBUG] Successfully uploaded block 149/348
[2026-03-22 21:06:06,109][utils.updater][DEBUG] Successfully uploaded block 150/348
[2026-03-22 21:06:06,110][utils.updater][DEBUG] Received data packet op=3, block=150, len=1284
[2026-03-22 21:06:06,214][utils.updater][DEBUG] Successfully uploaded block 150/348
[2026-03-22 21:06:06,214][utils.updater][DEBUG] Successfully uploaded block 151/348
[2026-03-22 21:06:06,215][utils.updater][DEBUG] Received data packet op=3, block=151, len=1284
[2026-03-22 21:06:06,319][utils.updater][DEBUG] Successfully uploaded block 151/348
[2026-03-22 21:06:06,319][utils.updater][DEBUG] Successfully uploaded block 152/348
[2026-03-22 21:06:06,320][utils.updater][DEBUG] Received data packet op=3, block=152, len=1284
[2026-03-22 21:06:06,424][utils.updater][DEBUG] Successfully uploaded block 152/348
[2026-03-22 21:06:06,424][utils.updater][DEBUG] Successfully uploaded block 153/348
[2026-03-22 21:06:06,425][utils.updater][DEBUG] Received data packet op=3, block=153, len=1284
[2026-03-22 21:06:06,529][utils.updater][DEBUG] Successfully uploaded block 153/348
[2026-03-22 21:06:06,529][utils.updater][DEBUG] Successfully uploaded block 154/348
[2026-03-22 21:06:06,530][utils.updater][DEBUG] Received data packet op=3, block=154, len=1284
[2026-03-22 21:06:06,634][utils.updater][DEBUG] Successfully uploaded block 154/348
[2026-03-22 21:06:06,634][utils.updater][DEBUG] Successfully uploaded block 155/348
[2026-03-22 21:06:06,635][utils.updater][DEBUG] Received data packet op=3, block=155, len=1284
[2026-03-22 21:06:06,739][utils.updater][DEBUG] Successfully uploaded block 155/348
[2026-03-22 21:06:06,739][utils.updater][DEBUG] Successfully uploaded block 156/348
[2026-03-22 21:06:06,740][utils.updater][DEBUG] Received data packet op=3, block=156, len=1284
[2026-03-22 21:06:06,844][utils.updater][DEBUG] Successfully uploaded block 156/348
[2026-03-22 21:06:06,844][utils.updater][DEBUG] Successfully uploaded block 157/348
[2026-03-22 21:06:06,845][utils.updater][DEBUG] Received data packet op=3, block=157, len=1284
[2026-03-22 21:06:06,949][utils.updater][DEBUG] Successfully uploaded block 157/348
[2026-03-22 21:06:06,949][utils.updater][DEBUG] Successfully uploaded block 158/348
[2026-03-22 21:06:06,950][utils.updater][DEBUG] Received data packet op=3, block=158, len=1284
[2026-03-22 21:06:07,054][utils.updater][DEBUG] Successfully uploaded block 158/348
[2026-03-22 21:06:07,054][utils.updater][DEBUG] Successfully uploaded block 159/348
[2026-03-22 21:06:07,055][utils.updater][DEBUG] Received data packet op=3, block=159, len=1284
[2026-03-22 21:06:07,159][utils.updater][DEBUG] Successfully uploaded block 159/348
[2026-03-22 21:06:07,159][utils.updater][DEBUG] Successfully uploaded block 160/348
[2026-03-22 21:06:07,160][utils.updater][DEBUG] Received data packet op=3, block=160, len=1284
[2026-03-22 21:06:07,264][utils.updater][DEBUG] Successfully uploaded block 160/348
[2026-03-22 21:06:07,264][utils.updater][DEBUG] Successfully uploaded block 161/348
[2026-03-22 21:06:07,265][utils.updater][DEBUG] Received data packet op=3, block=161, len=1284
[2026-03-22 21:06:07,369][utils.updater][DEBUG] Successfully uploaded block 161/348
[2026-03-22 21:06:07,369][utils.updater][DEBUG] Successfully uploaded block 162/348
[2026-03-22 21:06:07,370][utils.updater][DEBUG] Received data packet op=3, block=162, len=1284
[2026-03-22 21:06:07,474][utils.updater][DEBUG] Successfully uploaded block 162/348
[2026-03-22 21:06:07,474][utils.updater][DEBUG] Successfully uploaded block 163/348
[2026-03-22 21:06:07,475][utils.updater][DEBUG] Received data packet op=3, block=163, len=1284
[2026-03-22 21:06:07,579][utils.updater][DEBUG] Successfully uploaded block 163/348
[2026-03-22 21:06:07,579][utils.updater][DEBUG] Successfully uploaded block 164/348
[2026-03-22 21:06:07,580][utils.updater][DEBUG] Received data packet op=3, block=164, len=1284
[2026-03-22 21:06:07,684][utils.updater][DEBUG] Successfully uploaded block 164/348
[2026-03-22 21:06:07,684][utils.updater][DEBUG] Successfully uploaded block 165/348
[2026-03-22 21:06:07,685][utils.updater][DEBUG] Received data packet op=3, block=165, len=1284
[2026-03-22 21:06:07,789][utils.updater][DEBUG] Successfully uploaded block 165/348
[2026-03-22 21:06:07,789][utils.updater][DEBUG] Successfully uploaded block 166/348
[2026-03-22 21:06:07,790][utils.updater][DEBUG] Received data packet op=3, block=166, len=1284
[2026-03-22 21:06:07,894][utils.updater][DEBUG] Successfully uploaded block 166/348
[2026-03-22 21:06:07,894][utils.updater][DEBUG] Successfully uploaded block 167/348
[2026-03-22 21:06:07,895][utils.updater][DEBUG] Received data packet op=3, block=167, len=1284
[2026-03-22 21:06:07,999][utils.updater][DEBUG] Successfully uploaded block 167/348
[2026-03-22 21:06:07,999][utils.updater][DEBUG] Successfully uploaded block 168/348
[2026-03-22 21:06:08,000][utils.updater][DEBUG] Received data packet op=3, block=168, len=1284
[2026-03-22 21:06:08,104][utils.updater][DEBUG] Successfully uploaded block 168/348
[2026-03-22 21:06:08,104][utils.updater][DEBUG] Successfully uploaded block 169/348
[2026-03-22 21:06:08,105][utils.updater][DEBUG] Received data packet op=3, block=169, len=1284
[2026-03-22 21:06:08,209][utils.updater][DEBUG] Successfully uploaded block 169/348
[2026-03-22 21:06:08,209][utils.updater][DEBUG] Successfully uploaded block 170/348
[2026-03-22 21:06:08,210][utils.updater][DEBUG] Received data packet op=3, block=170, len=1284
[2026-03-22 21:06:08,314][utils.updater][DEBUG] Successfully uploaded block 170/348
[2026-03-22 21:06:08,314][utils.updater][DEBUG] Successfully uploaded block 171/348
[2026-03-22 21:06:08,315][utils.updater][DEBUG] Received data packet op=3, block=171, len=1284
[2026-03-22 21:06:08,419][utils.updater][DEBUG] Successfully uploaded block 171/348
[2026-03-22 21:06:08,419][utils.updater][DEBUG] Successfully uploaded block 172/348
[2026-03-22 21:06:08,420][utils.updater][DEBUG] Received data packet op=3, block=172, len=1284
[2026-03-22 21:06:08,524][utils.updater][DEBUG] Successfully uploaded block 172/348
[2026-03-22 21:06:08,524][utils.updater][DEBUG] Successfully uploaded block 173/348
[2026-03-22 21:06:08,525][utils.updater][DEBUG] Received data packet op=3, block=173, len=1284
[2026-03-22 21:06:08,629][utils.updater][DEBUG] Successfully uploaded block 173/348
[2026-03-22 21:06:08,629][utils.updater][DEBUG] Successfully uploaded block 174/348
[2026-03-22 21:06:08,630][utils.updater][DEBUG] Received data packet op=3, block=174, len=1284
[2026-03-22 21:06:08,734][utils.updater][DEBUG] Successfully uploaded block 174/348
[2026-03-22 21:06:08,734][utils.updater][DEBUG] Successfully uploaded block 175/348
[2026-03-22 21:06:08,735][utils.updater][DEBUG] Received data packet op=3, block=175, len=1284
[2026-03-22 21:06:08,839][utils.updater][DEBUG] Successfully uploaded block 175/348
[2026-03-22 21:06:08,839][utils.updater][DEBUG] Successfully uploaded block 176/348
[2026-03-22 21:06:08,840][utils.updater][DEBUG] Received data packet op=3, block=176, len=1284
[2026-03-22 21:06:08,944][utils.updater][DEBUG] Successfully uploaded block 176/348
[2026-03-22 21:06:08,944][utils.updater][DEBUG] Successfully uploaded block 177/348
[2026-03-22 21:06:08,945][utils.updater][DEBUG] Received data packet op=3, block=177, len=1284
[2026-03-22 21:06:09,049][utils.updater][DEBUG] Successfully uploaded block 177/348
[2026-03-22 21:06:09,049][utils.updater][DEBUG] Successfully uploaded block 178/348
[2026-03-22 21:06:09,050][utils.updater][DEBUG] Received data packet op=3, block=178, len=1284
[2026-03-22 21:06:09,154][utils.updater][DEBUG] Successfully uploaded block 178/348
[2026-03-22 21:06:09,154][utils.updater][DEBUG] Successfully uploaded block 179/348
[2026-03-22 21:06:09,155][utils.updater][DEBUG] Received data packet op=3, block=179, len=1284
[2026-03-22 21:06:09,259][utils.updater][DEBUG] Successfully uploaded block 179/348
[2026-03-22 21:06:09,259][utils.updater][DEBUG] Successfully uploaded block 180/348
[2026-03-22 21:06:09,260][utils.updater][DEBUG] Received data packet op=3, block=180, len=1284
[2026-03-22 21:06:09,364][utils.updater][DEBUG] Successfully uploaded block 180/348
[2026-03-22 21:06:09,364][utils.updater][DEBUG] Successfully uploaded block 181/348
[2026-03-22 21:06:09,365][utils.updater][DEBUG] Received data packet op=3, block=181, len=1284
[2026-03-22 21:06:09,469][utils.updater][DEBUG] Successfully uploaded block 181/348
[2026-03-22 21:06:09,469][utils.updater][DEBUG] Successfully uploaded block 182/348
[2026-03-22 21:06:09,470][utils.updater][DEBUG] Received data packet op=3, block=182, len=1284
[2026-03-22 21:06:09,574][utils.updater][DEBUG] Successfully uploaded block 182/348
[2026-03-22 21:06:09,574][utils.updater][DEBUG] Successfully uploaded block 183/348
[2026-03-22 21:06:09,575][utils.updater][DEBUG] Received data packet op=3, block=183, len=1284
[2026-03-22 21:06:09,679][utils.updater][DEBUG] Successfully uploaded block 183/348
[2026-03-22 21:06:09,679][utils.updater][DEBUG] Successfully uploaded block 184/348
[2026-03-22 21:06:09,680][utils.updater][DEBUG] Received data packet op=3, block=184, len=1284
[2026-03-22 21:06:09,784][utils.updater][DEBUG] Successfully uploaded block 184/348
[2026-03-22 21:06:09,784][utils.updater][DEBUG] Successfully uploaded block 185/348
[2026-03-22 21:06:09,785][utils.updater][DEBUG] Received data packet op=3, block=185, len=1284
[2026-03-22 21:06:09,889][utils.updater][DEBUG] Successfully uploaded block 185/348
[2026-03-22 21:06:09,889][utils.updater][DEBUG] Successfully uploaded block 186/348
[2026-03-22 21:06:09,890][utils.updater][DEBUG] Received data packet op=3, block=186, len=1284
[2026-03-22 21:06:09,994][utils.updater][DEBUG] Successfully uploaded block 186/348
[2026-03-22 21:06:09,994][utils.updater][DEBUG] Successfully uploaded block 187/348
[2026-03-22 21:06:09,995][utils.updater][DEBUG] Received data packet op=3, block=187, len=1284
[2026-03-22 21:06:10,099][utils.updater][DEBUG] Successfully uploaded block 187/348
[2026-03-22 21:06:10,099][utils.updater][DEBUG] Successfully uploaded block 188/348
[2026-03-22 21:06:10,100][utils.updater][DEBUG] Received data packet op=3, block=188, len=1284
[2026-03-22 21:06:10,204][utils.updater][DEBUG] Successfully uploaded block 188/348
[2026-03-22 21:06:10,204][utils.updater][DEBUG] Successfully uploaded block 189/348
[2026-03-22 21:06:10,205][utils.updater][DEBUG] Received data packet op=3, block=189, len=1284
[2026-03-22 21:06:10,309][utils.updater][DEBUG] Successfully uploaded block 189/348
[2026-03-22 21:06:10,309][utils.updater][DEBUG] Successfully uploaded block 190/348
[2026-03-22 21:06:10,310][utils.updater][DEBUG] Received data packet op=3, block=190, len=1284
[2026-03-22 21:06:10,414][utils.updater][DEBUG] Successfully uploaded block 190/348
[2026-03-22 21:06:10,414][utils.updater][DEBUG] Successfully uploaded block 191/348
[2026-03-22 21:06:10,415][utils.updater][DEBUG] Received data packet op=3, block=191, len=1284
[2026-03-22 21:06:10,519][utils.updater][DEBUG] Successfully uploaded block 191/348
[2026-03-22 21:06:10,519][utils.updater][DEBUG] Successfully uploaded block 192/348
[2026-03-22 21:06:10,520][utils.updater][DEBUG] Received data packet op=3, block=192, len=1284
[2026-03-22 21:06:10,624][utils.updater][DEBUG] Successfully uploaded block 192/348
[2026-03-22 21:06:10,624][utils.updater][DEBUG] Successfully uploaded block 193/348
[2026-03-22 21:06:10,625][utils.updater][DEBUG] Received data packet op=3, block=193, len=1284
[2026-03-22 21:06:10,729][utils.updater][DEBUG] Successfully uploaded block 193/348
[2026-03-22 21:06:10,729][utils.updater][DEBUG] Successfully uploaded block 194/348
[2026-03-22 21:06:10,730][utils.updater][DEBUG] Received data packet op=3, block=194, len=1284
[2026-03-22 21:06:10,834][utils.updater][DEBUG] Successfully uploaded block 194/348
[2026-03-22 21:06:10,834][utils.updater][DEBUG] Successfully uploaded block 195/348
[2026-03-22 21:06:10,835][utils.updater][DEBUG] Received data packet op=3, block=195, len=1284
[2026-03-22 21:06:10,939][utils.updater][DEBUG] Successfully uploaded block 195/348
[2026-03-22 21:06:10,939][utils.updater][DEBUG] Successfully uploaded block 196/348
[2026-03-22 21:06:10,940][utils.updater][DEBUG] Received data packet op=3, block=196, len=1284
[2026-03-22 21:06:11,046][utils.updater][DEBUG] Successfully uploaded block 196/348
[2026-03-22 21:06:11,046][utils.updater][DEBUG] Successfully uploaded block 197/348
[2026-03-22 21:06:11,047][utils.updater][DEBUG] Received data packet op=3, block=197, len=1284
[2026-03-22 21:06:11,152][utils.updater][DEBUG] Successfully uploaded block 197/348
[2026-03-22 21:06:11,152][utils.updater][DEBUG] Successfully uploaded block 198/348
[2026-03-22 21:06:11,153][utils.updater][DEBUG] Received data packet op=3, block=198, len=1284
[2026-03-22 21:06:11,257][utils.updater][DEBUG] Successfully uploaded block 198/348
[2026-03-22 21:06:11,257][utils.updater][DEBUG] Successfully uploaded block 199/348
[2026-03-22 21:06:11,258][utils.updater][DEBUG] Received data packet op=3, block=199, len=1284
[2026-03-22 21:06:11,362][utils.updater][DEBUG] Successfully uploaded block 199/348
[2026-03-22 21:06:11,362][utils.updater][DEBUG] Successfully uploaded block 200/348
[2026-03-22 21:06:11,363][utils.updater][DEBUG] Received data packet op=3, block=200, len=1284
[2026-03-22 21:06:11,467][utils.updater][DEBUG] Successfully uploaded block 200/348
[2026-03-22 21:06:11,467][utils.updater][DEBUG] Successfully uploaded block 201/348
[2026-03-22 21:06:11,468][utils.updater][DEBUG] Received data packet op=3, block=201, len=1284
[2026-03-22 21:06:11,572][utils.updater][DEBUG] Successfully uploaded block 201/348
[2026-03-22 21:06:11,572][utils.updater][DEBUG] Successfully uploaded block 202/348
[2026-03-22 21:06:11,573][utils.updater][DEBUG] Received data packet op=3, block=202, len=1284
[2026-03-22 21:06:11,677][utils.updater][DEBUG] Successfully uploaded block 202/348
[2026-03-22 21:06:11,677][utils.updater][DEBUG] Successfully uploaded block 203/348
[2026-03-22 21:06:11,678][utils.updater][DEBUG] Received data packet op=3, block=203, len=1284
[2026-03-22 21:06:11,782][utils.updater][DEBUG] Successfully uploaded block 203/348
[2026-03-22 21:06:11,782][utils.updater][DEBUG] Successfully uploaded block 204/348
[2026-03-22 21:06:11,783][utils.updater][DEBUG] Received data packet op=3, block=204, len=1284
[2026-03-22 21:06:11,887][utils.updater][DEBUG] Successfully uploaded block 204/348
[2026-03-22 21:06:11,887][utils.updater][DEBUG] Successfully uploaded block 205/348
[2026-03-22 21:06:11,888][utils.updater][DEBUG] Received data packet op=3, block=205, len=1284
[2026-03-22 21:06:11,992][utils.updater][DEBUG] Successfully uploaded block 205/348
[2026-03-22 21:06:11,992][utils.updater][DEBUG] Successfully uploaded block 206/348
[2026-03-22 21:06:11,993][utils.updater][DEBUG] Received data packet op=3, block=206, len=1284
[2026-03-22 21:06:12,097][utils.updater][DEBUG] Successfully uploaded block 206/348
[2026-03-22 21:06:12,097][utils.updater][DEBUG] Successfully uploaded block 207/348
[2026-03-22 21:06:12,098][utils.updater][DEBUG] Received data packet op=3, block=207, len=1284
[2026-03-22 21:06:12,203][utils.updater][DEBUG] Successfully uploaded block 207/348
[2026-03-22 21:06:12,203][utils.updater][DEBUG] Successfully uploaded block 208/348
[2026-03-22 21:06:12,204][utils.updater][DEBUG] Received data packet op=3, block=208, len=1284
[2026-03-22 21:06:12,309][utils.updater][DEBUG] Successfully uploaded block 208/348
[2026-03-22 21:06:12,309][utils.updater][DEBUG] Successfully uploaded block 209/348
[2026-03-22 21:06:12,310][utils.updater][DEBUG] Received data packet op=3, block=209, len=1284
[2026-03-22 21:06:12,414][utils.updater][DEBUG] Successfully uploaded block 209/348
[2026-03-22 21:06:12,414][utils.updater][DEBUG] Successfully uploaded block 210/348
[2026-03-22 21:06:12,415][utils.updater][DEBUG] Received data packet op=3, block=210, len=1284
[2026-03-22 21:06:12,519][utils.updater][DEBUG] Successfully uploaded block 210/348
[2026-03-22 21:06:12,519][utils.updater][DEBUG] Successfully uploaded block 211/348
[2026-03-22 21:06:12,520][utils.updater][DEBUG] Received data packet op=3, block=211, len=1284
[2026-03-22 21:06:12,625][utils.updater][DEBUG] Successfully uploaded block 211/348
[2026-03-22 21:06:12,625][utils.updater][DEBUG] Successfully uploaded block 212/348
[2026-03-22 21:06:12,626][utils.updater][DEBUG] Received data packet op=3, block=212, len=1284
[2026-03-22 21:06:12,730][utils.updater][DEBUG] Successfully uploaded block 212/348
[2026-03-22 21:06:12,730][utils.updater][DEBUG] Successfully uploaded block 213/348
[2026-03-22 21:06:12,731][utils.updater][DEBUG] Received data packet op=3, block=213, len=1284
[2026-03-22 21:06:12,836][utils.updater][DEBUG] Successfully uploaded block 213/348
[2026-03-22 21:06:12,836][utils.updater][DEBUG] Successfully uploaded block 214/348
[2026-03-22 21:06:12,837][utils.updater][DEBUG] Received data packet op=3, block=214, len=1284
[2026-03-22 21:06:12,942][utils.updater][DEBUG] Successfully uploaded block 214/348
[2026-03-22 21:06:12,942][utils.updater][DEBUG] Successfully uploaded block 215/348
[2026-03-22 21:06:12,943][utils.updater][DEBUG] Received data packet op=3, block=215, len=1284
[2026-03-22 21:06:13,047][utils.updater][DEBUG] Successfully uploaded block 215/348
[2026-03-22 21:06:13,047][utils.updater][DEBUG] Successfully uploaded block 216/348
[2026-03-22 21:06:13,048][utils.updater][DEBUG] Received data packet op=3, block=216, len=1284
[2026-03-22 21:06:13,152][utils.updater][DEBUG] Successfully uploaded block 216/348
[2026-03-22 21:06:13,152][utils.updater][DEBUG] Successfully uploaded block 217/348
[2026-03-22 21:06:13,153][utils.updater][DEBUG] Received data packet op=3, block=217, len=1284
[2026-03-22 21:06:13,257][utils.updater][DEBUG] Successfully uploaded block 217/348
[2026-03-22 21:06:13,257][utils.updater][DEBUG] Successfully uploaded block 218/348
[2026-03-22 21:06:13,258][utils.updater][DEBUG] Received data packet op=3, block=218, len=1284
[2026-03-22 21:06:13,362][utils.updater][DEBUG] Successfully uploaded block 218/348
[2026-03-22 21:06:13,362][utils.updater][DEBUG] Successfully uploaded block 219/348
[2026-03-22 21:06:13,363][utils.updater][DEBUG] Received data packet op=3, block=219, len=1284
[2026-03-22 21:06:13,467][utils.updater][DEBUG] Successfully uploaded block 219/348
[2026-03-22 21:06:13,467][utils.updater][DEBUG] Successfully uploaded block 220/348
[2026-03-22 21:06:13,468][utils.updater][DEBUG] Received data packet op=3, block=220, len=1284
[2026-03-22 21:06:13,572][utils.updater][DEBUG] Successfully uploaded block 220/348
[2026-03-22 21:06:13,572][utils.updater][DEBUG] Successfully uploaded block 221/348
[2026-03-22 21:06:13,573][utils.updater][DEBUG] Received data packet op=3, block=221, len=1284
[2026-03-22 21:06:13,677][utils.updater][DEBUG] Successfully uploaded block 221/348
[2026-03-22 21:06:13,677][utils.updater][DEBUG] Successfully uploaded block 222/348
[2026-03-22 21:06:13,678][utils.updater][DEBUG] Received data packet op=3, block=222, len=1284
[2026-03-22 21:06:13,782][utils.updater][DEBUG] Successfully uploaded block 222/348
[2026-03-22 21:06:13,782][utils.updater][DEBUG] Successfully uploaded block 223/348
[2026-03-22 21:06:13,783][utils.updater][DEBUG] Received data packet op=3, block=223, len=1284
[2026-03-22 21:06:13,887][utils.updater][DEBUG] Successfully uploaded block 223/348
[2026-03-22 21:06:13,887][utils.updater][DEBUG] Successfully uploaded block 224/348
[2026-03-22 21:06:13,888][utils.updater][DEBUG] Received data packet op=3, block=224, len=1284
[2026-03-22 21:06:13,992][utils.updater][DEBUG] Successfully uploaded block 224/348
[2026-03-22 21:06:13,992][utils.updater][DEBUG] Successfully uploaded block 225/348
[2026-03-22 21:06:13,993][utils.updater][DEBUG] Received data packet op=3, block=225, len=1284
[2026-03-22 21:06:14,097][utils.updater][DEBUG] Successfully uploaded block 225/348
[2026-03-22 21:06:14,097][utils.updater][DEBUG] Successfully uploaded block 226/348
[2026-03-22 21:06:14,098][utils.updater][DEBUG] Received data packet op=3, block=226, len=1284
[2026-03-22 21:06:14,202][utils.updater][DEBUG] Successfully uploaded block 226/348
[2026-03-22 21:06:14,202][utils.updater][DEBUG] Successfully uploaded block 227/348
[2026-03-22 21:06:14,203][utils.updater][DEBUG] Received data packet op=3, block=227, len=1284
[2026-03-22 21:06:14,307][utils.updater][DEBUG] Successfully uploaded block 227/348
[2026-03-22 21:06:14,307][utils.updater][DEBUG] Successfully uploaded block 228/348
[2026-03-22 21:06:14,308][utils.updater][DEBUG] Received data packet op=3, block=228, len=1284
[2026-03-22 21:06:14,412][utils.updater][DEBUG] Successfully uploaded block 228/348
[2026-03-22 21:06:14,412][utils.updater][DEBUG] Successfully uploaded block 229/348
[2026-03-22 21:06:14,413][utils.updater][DEBUG] Received data packet op=3, block=229, len=1284
[2026-03-22 21:06:14,517][utils.updater][DEBUG] Successfully uploaded block 229/348
[2026-03-22 21:06:14,517][utils.updater][DEBUG] Successfully uploaded block 230/348
[2026-03-22 21:06:14,518][utils.updater][DEBUG] Received data packet op=3, block=230, len=1284
[2026-03-22 21:06:14,622][utils.updater][DEBUG] Successfully uploaded block 230/348
[2026-03-22 21:06:14,622][utils.updater][DEBUG] Successfully uploaded block 231/348
[2026-03-22 21:06:14,623][utils.updater][DEBUG] Received data packet op=3, block=231, len=1284
[2026-03-22 21:06:14,727][utils.updater][DEBUG] Successfully uploaded block 231/348
[2026-03-22 21:06:14,727][utils.updater][DEBUG] Successfully uploaded block 232/348
[2026-03-22 21:06:14,728][utils.updater][DEBUG] Received data packet op=3, block=232, len=1284
[2026-03-22 21:06:14,832][utils.updater][DEBUG] Successfully uploaded block 232/348
[2026-03-22 21:06:14,832][utils.updater][DEBUG] Successfully uploaded block 233/348
[2026-03-22 21:06:14,833][utils.updater][DEBUG] Received data packet op=3, block=233, len=1284
[2026-03-22 21:06:14,937][utils.updater][DEBUG] Successfully uploaded block 233/348
[2026-03-22 21:06:14,937][utils.updater][DEBUG] Successfully uploaded block 234/348
[2026-03-22 21:06:14,938][utils.updater][DEBUG] Received data packet op=3, block=234, len=1284
[2026-03-22 21:06:15,042][utils.updater][DEBUG] Successfully uploaded block 234/348
[2026-03-22 21:06:15,042][utils.updater][DEBUG] Successfully uploaded block 235/348
[2026-03-22 21:06:15,043][utils.updater][DEBUG] Received data packet op=3, block=235, len=1284
[2026-03-22 21:06:15,150][utils.updater][DEBUG] Successfully uploaded block 235/348
[2026-03-22 21:06:15,150][utils.updater][DEBUG] Successfully uploaded block 236/348
[2026-03-22 21:06:15,151][utils.updater][DEBUG] Received data packet op=3, block=236, len=1284
[2026-03-22 21:06:15,255][utils.updater][DEBUG] Successfully uploaded block 236/348
[2026-03-22 21:06:15,255][utils.updater][DEBUG] Successfully uploaded block 237/348
[2026-03-22 21:06:15,256][utils.updater][DEBUG] Received data packet op=3, block=237, len=1284
[2026-03-22 21:06:15,361][utils.updater][DEBUG] Successfully uploaded block 237/348
[2026-03-22 21:06:15,361][utils.updater][DEBUG] Successfully uploaded block 238/348
[2026-03-22 21:06:15,362][utils.updater][DEBUG] Received data packet op=3, block=238, len=1284
[2026-03-22 21:06:15,467][utils.updater][DEBUG] Successfully uploaded block 238/348
[2026-03-22 21:06:15,467][utils.updater][DEBUG] Successfully uploaded block 239/348
[2026-03-22 21:06:15,468][utils.updater][DEBUG] Received data packet op=3, block=239, len=1284
[2026-03-22 21:06:15,572][utils.updater][DEBUG] Successfully uploaded block 239/348
[2026-03-22 21:06:15,572][utils.updater][DEBUG] Successfully uploaded block 240/348
[2026-03-22 21:06:15,573][utils.updater][DEBUG] Received data packet op=3, block=240, len=1284
[2026-03-22 21:06:15,678][utils.updater][DEBUG] Successfully uploaded block 240/348
[2026-03-22 21:06:15,678][utils.updater][DEBUG] Successfully uploaded block 241/348
[2026-03-22 21:06:15,679][utils.updater][DEBUG] Received data packet op=3, block=241, len=1284
[2026-03-22 21:06:15,784][utils.updater][DEBUG] Successfully uploaded block 241/348
[2026-03-22 21:06:15,784][utils.updater][DEBUG] Successfully uploaded block 242/348
[2026-03-22 21:06:15,785][utils.updater][DEBUG] Received data packet op=3, block=242, len=1284
[2026-03-22 21:06:15,889][utils.updater][DEBUG] Successfully uploaded block 242/348
[2026-03-22 21:06:15,889][utils.updater][DEBUG] Successfully uploaded block 243/348
[2026-03-22 21:06:15,890][utils.updater][DEBUG] Received data packet op=3, block=243, len=1284
[2026-03-22 21:06:15,994][utils.updater][DEBUG] Successfully uploaded block 243/348
[2026-03-22 21:06:15,994][utils.updater][DEBUG] Successfully uploaded block 244/348
[2026-03-22 21:06:15,995][utils.updater][DEBUG] Received data packet op=3, block=244, len=1284
[2026-03-22 21:06:16,099][utils.updater][DEBUG] Successfully uploaded block 244/348
[2026-03-22 21:06:16,099][utils.updater][DEBUG] Successfully uploaded block 245/348
[2026-03-22 21:06:16,100][utils.updater][DEBUG] Received data packet op=3, block=245, len=1284
[2026-03-22 21:06:16,204][utils.updater][DEBUG] Successfully uploaded block 245/348
[2026-03-22 21:06:16,204][utils.updater][DEBUG] Successfully uploaded block 246/348
[2026-03-22 21:06:16,205][utils.updater][DEBUG] Received data packet op=3, block=246, len=1284
[2026-03-22 21:06:16,309][utils.updater][DEBUG] Successfully uploaded block 246/348
[2026-03-22 21:06:16,309][utils.updater][DEBUG] Successfully uploaded block 247/348
[2026-03-22 21:06:16,310][utils.updater][DEBUG] Received data packet op=3, block=247, len=1284
[2026-03-22 21:06:16,414][utils.updater][DEBUG] Successfully uploaded block 247/348
[2026-03-22 21:06:16,414][utils.updater][DEBUG] Successfully uploaded block 248/348
[2026-03-22 21:06:16,415][utils.updater][DEBUG] Received data packet op=3, block=248, len=1284
[2026-03-22 21:06:16,519][utils.updater][DEBUG] Successfully uploaded block 248/348
[2026-03-22 21:06:16,519][utils.updater][DEBUG] Successfully uploaded block 249/348
[2026-03-22 21:06:16,520][utils.updater][DEBUG] Received data packet op=3, block=249, len=1284
[2026-03-22 21:06:16,624][utils.updater][DEBUG] Successfully uploaded block 249/348
[2026-03-22 21:06:16,624][utils.updater][DEBUG] Successfully uploaded block 250/348
[2026-03-22 21:06:16,625][utils.updater][DEBUG] Received data packet op=3, block=250, len=1284
[2026-03-22 21:06:16,729][utils.updater][DEBUG] Successfully uploaded block 250/348
[2026-03-22 21:06:16,729][utils.updater][DEBUG] Successfully uploaded block 251/348
[2026-03-22 21:06:16,730][utils.updater][DEBUG] Received data packet op=3, block=251, len=1284
[2026-03-22 21:06:16,834][utils.updater][DEBUG] Successfully uploaded block 251/348
[2026-03-22 21:06:16,834][utils.updater][DEBUG] Successfully uploaded block 252/348
[2026-03-22 21:06:16,835][utils.updater][DEBUG] Received data packet op=3, block=252, len=1284
[2026-03-22 21:06:16,939][utils.updater][DEBUG] Successfully uploaded block 252/348
[2026-03-22 21:06:16,939][utils.updater][DEBUG] Successfully uploaded block 253/348
[2026-03-22 21:06:16,940][utils.updater][DEBUG] Received data packet op=3, block=253, len=1284
[2026-03-22 21:06:17,046][utils.updater][DEBUG] Successfully uploaded block 253/348
[2026-03-22 21:06:17,047][utils.updater][DEBUG] Successfully uploaded block 254/348
[2026-03-22 21:06:17,047][utils.updater][DEBUG] Received data packet op=3, block=254, len=1284
[2026-03-22 21:06:17,152][utils.updater][DEBUG] Successfully uploaded block 254/348
[2026-03-22 21:06:17,152][utils.updater][DEBUG] Successfully uploaded block 255/348
[2026-03-22 21:06:17,153][utils.updater][DEBUG] Received data packet op=3, block=255, len=1284
[2026-03-22 21:06:17,257][utils.updater][DEBUG] Successfully uploaded block 255/348
[2026-03-22 21:06:17,257][utils.updater][DEBUG] Successfully uploaded block 256/348
[2026-03-22 21:06:17,258][utils.updater][DEBUG] Received data packet op=3, block=256, len=1284
[2026-03-22 21:06:17,362][utils.updater][DEBUG] Successfully uploaded block 256/348
[2026-03-22 21:06:17,362][utils.updater][DEBUG] Successfully uploaded block 257/348
[2026-03-22 21:06:17,363][utils.updater][DEBUG] Received data packet op=3, block=257, len=1284
[2026-03-22 21:06:17,467][utils.updater][DEBUG] Successfully uploaded block 257/348
[2026-03-22 21:06:17,467][utils.updater][DEBUG] Successfully uploaded block 258/348
[2026-03-22 21:06:17,468][utils.updater][DEBUG] Received data packet op=3, block=258, len=1284
[2026-03-22 21:06:17,572][utils.updater][DEBUG] Successfully uploaded block 258/348
[2026-03-22 21:06:17,572][utils.updater][DEBUG] Successfully uploaded block 259/348
[2026-03-22 21:06:17,573][utils.updater][DEBUG] Received data packet op=3, block=259, len=1284
[2026-03-22 21:06:17,677][utils.updater][DEBUG] Successfully uploaded block 259/348
[2026-03-22 21:06:17,677][utils.updater][DEBUG] Successfully uploaded block 260/348
[2026-03-22 21:06:17,678][utils.updater][DEBUG] Received data packet op=3, block=260, len=1284
[2026-03-22 21:06:17,783][utils.updater][DEBUG] Successfully uploaded block 260/348
[2026-03-22 21:06:17,783][utils.updater][DEBUG] Successfully uploaded block 261/348
[2026-03-22 21:06:17,784][utils.updater][DEBUG] Received data packet op=3, block=261, len=1284
[2026-03-22 21:06:17,889][utils.updater][DEBUG] Successfully uploaded block 261/348
[2026-03-22 21:06:17,889][utils.updater][DEBUG] Successfully uploaded block 262/348
[2026-03-22 21:06:17,890][utils.updater][DEBUG] Received data packet op=3, block=262, len=1284
[2026-03-22 21:06:17,995][utils.updater][DEBUG] Successfully uploaded block 262/348
[2026-03-22 21:06:17,995][utils.updater][DEBUG] Successfully uploaded block 263/348
[2026-03-22 21:06:17,996][utils.updater][DEBUG] Received data packet op=3, block=263, len=1284
[2026-03-22 21:06:18,100][utils.updater][DEBUG] Successfully uploaded block 263/348
[2026-03-22 21:06:18,100][utils.updater][DEBUG] Successfully uploaded block 264/348
[2026-03-22 21:06:18,101][utils.updater][DEBUG] Received data packet op=3, block=264, len=1284
[2026-03-22 21:06:18,205][utils.updater][DEBUG] Successfully uploaded block 264/348
[2026-03-22 21:06:18,205][utils.updater][DEBUG] Successfully uploaded block 265/348
[2026-03-22 21:06:18,206][utils.updater][DEBUG] Received data packet op=3, block=265, len=1284
[2026-03-22 21:06:18,311][utils.updater][DEBUG] Successfully uploaded block 265/348
[2026-03-22 21:06:18,311][utils.updater][DEBUG] Successfully uploaded block 266/348
[2026-03-22 21:06:18,312][utils.updater][DEBUG] Received data packet op=3, block=266, len=1284
[2026-03-22 21:06:18,416][utils.updater][DEBUG] Successfully uploaded block 266/348
[2026-03-22 21:06:18,416][utils.updater][DEBUG] Successfully uploaded block 267/348
[2026-03-22 21:06:18,417][utils.updater][DEBUG] Received data packet op=3, block=267, len=1284
[2026-03-22 21:06:18,522][utils.updater][DEBUG] Successfully uploaded block 267/348
[2026-03-22 21:06:18,522][utils.updater][DEBUG] Successfully uploaded block 268/348
[2026-03-22 21:06:18,523][utils.updater][DEBUG] Received data packet op=3, block=268, len=1284
[2026-03-22 21:06:18,628][utils.updater][DEBUG] Successfully uploaded block 268/348
[2026-03-22 21:06:18,628][utils.updater][DEBUG] Successfully uploaded block 269/348
[2026-03-22 21:06:18,629][utils.updater][DEBUG] Received data packet op=3, block=269, len=1284
[2026-03-22 21:06:18,733][utils.updater][DEBUG] Successfully uploaded block 269/348
[2026-03-22 21:06:18,733][utils.updater][DEBUG] Successfully uploaded block 270/348
[2026-03-22 21:06:18,734][utils.updater][DEBUG] Received data packet op=3, block=270, len=1284
[2026-03-22 21:06:18,838][utils.updater][DEBUG] Successfully uploaded block 270/348
[2026-03-22 21:06:18,838][utils.updater][DEBUG] Successfully uploaded block 271/348
[2026-03-22 21:06:18,839][utils.updater][DEBUG] Received data packet op=3, block=271, len=1284
[2026-03-22 21:06:18,943][utils.updater][DEBUG] Successfully uploaded block 271/348
[2026-03-22 21:06:18,943][utils.updater][DEBUG] Successfully uploaded block 272/348
[2026-03-22 21:06:18,944][utils.updater][DEBUG] Received data packet op=3, block=272, len=1284
[2026-03-22 21:06:19,048][utils.updater][DEBUG] Successfully uploaded block 272/348
[2026-03-22 21:06:19,048][utils.updater][DEBUG] Successfully uploaded block 273/348
[2026-03-22 21:06:19,049][utils.updater][DEBUG] Received data packet op=3, block=273, len=1284
[2026-03-22 21:06:19,153][utils.updater][DEBUG] Successfully uploaded block 273/348
[2026-03-22 21:06:19,153][utils.updater][DEBUG] Successfully uploaded block 274/348
[2026-03-22 21:06:19,154][utils.updater][DEBUG] Received data packet op=3, block=274, len=1284
[2026-03-22 21:06:19,258][utils.updater][DEBUG] Successfully uploaded block 274/348
[2026-03-22 21:06:19,258][utils.updater][DEBUG] Successfully uploaded block 275/348
[2026-03-22 21:06:19,259][utils.updater][DEBUG] Received data packet op=3, block=275, len=1284
[2026-03-22 21:06:19,363][utils.updater][DEBUG] Successfully uploaded block 275/348
[2026-03-22 21:06:19,363][utils.updater][DEBUG] Successfully uploaded block 276/348
[2026-03-22 21:06:19,364][utils.updater][DEBUG] Received data packet op=3, block=276, len=1284
[2026-03-22 21:06:19,468][utils.updater][DEBUG] Successfully uploaded block 276/348
[2026-03-22 21:06:19,468][utils.updater][DEBUG] Successfully uploaded block 277/348
[2026-03-22 21:06:19,469][utils.updater][DEBUG] Received data packet op=3, block=277, len=1284
[2026-03-22 21:06:19,573][utils.updater][DEBUG] Successfully uploaded block 277/348
[2026-03-22 21:06:19,573][utils.updater][DEBUG] Successfully uploaded block 278/348
[2026-03-22 21:06:19,574][utils.updater][DEBUG] Received data packet op=3, block=278, len=1284
[2026-03-22 21:06:19,678][utils.updater][DEBUG] Successfully uploaded block 278/348
[2026-03-22 21:06:19,678][utils.updater][DEBUG] Successfully uploaded block 279/348
[2026-03-22 21:06:19,679][utils.updater][DEBUG] Received data packet op=3, block=279, len=1284
[2026-03-22 21:06:19,783][utils.updater][DEBUG] Successfully uploaded block 279/348
[2026-03-22 21:06:19,783][utils.updater][DEBUG] Successfully uploaded block 280/348
[2026-03-22 21:06:19,784][utils.updater][DEBUG] Received data packet op=3, block=280, len=1284
[2026-03-22 21:06:19,888][utils.updater][DEBUG] Successfully uploaded block 280/348
[2026-03-22 21:06:19,888][utils.updater][DEBUG] Successfully uploaded block 281/348
[2026-03-22 21:06:19,889][utils.updater][DEBUG] Received data packet op=3, block=281, len=1284
[2026-03-22 21:06:19,993][utils.updater][DEBUG] Successfully uploaded block 281/348
[2026-03-22 21:06:19,993][utils.updater][DEBUG] Successfully uploaded block 282/348
[2026-03-22 21:06:19,994][utils.updater][DEBUG] Received data packet op=3, block=282, len=1284
[2026-03-22 21:06:20,098][utils.updater][DEBUG] Successfully uploaded block 282/348
[2026-03-22 21:06:20,098][utils.updater][DEBUG] Successfully uploaded block 283/348
[2026-03-22 21:06:20,099][utils.updater][DEBUG] Received data packet op=3, block=283, len=1284
[2026-03-22 21:06:20,203][utils.updater][DEBUG] Successfully uploaded block 283/348
[2026-03-22 21:06:20,203][utils.updater][DEBUG] Successfully uploaded block 284/348
[2026-03-22 21:06:20,204][utils.updater][DEBUG] Received data packet op=3, block=284, len=1284
[2026-03-22 21:06:20,308][utils.updater][DEBUG] Successfully uploaded block 284/348
[2026-03-22 21:06:20,308][utils.updater][DEBUG] Successfully uploaded block 285/348
[2026-03-22 21:06:20,309][utils.updater][DEBUG] Received data packet op=3, block=285, len=1284
[2026-03-22 21:06:20,413][utils.updater][DEBUG] Successfully uploaded block 285/348
[2026-03-22 21:06:20,413][utils.updater][DEBUG] Successfully uploaded block 286/348
[2026-03-22 21:06:20,414][utils.updater][DEBUG] Received data packet op=3, block=286, len=1284
[2026-03-22 21:06:20,518][utils.updater][DEBUG] Successfully uploaded block 286/348
[2026-03-22 21:06:20,518][utils.updater][DEBUG] Successfully uploaded block 287/348
[2026-03-22 21:06:20,519][utils.updater][DEBUG] Received data packet op=3, block=287, len=1284
[2026-03-22 21:06:20,623][utils.updater][DEBUG] Successfully uploaded block 287/348
[2026-03-22 21:06:20,623][utils.updater][DEBUG] Successfully uploaded block 288/348
[2026-03-22 21:06:20,624][utils.updater][DEBUG] Received data packet op=3, block=288, len=1284
[2026-03-22 21:06:20,728][utils.updater][DEBUG] Successfully uploaded block 288/348
[2026-03-22 21:06:20,728][utils.updater][DEBUG] Successfully uploaded block 289/348
[2026-03-22 21:06:20,729][utils.updater][DEBUG] Received data packet op=3, block=289, len=1284
[2026-03-22 21:06:20,833][utils.updater][DEBUG] Successfully uploaded block 289/348
[2026-03-22 21:06:20,833][utils.updater][DEBUG] Successfully uploaded block 290/348
[2026-03-22 21:06:20,834][utils.updater][DEBUG] Received data packet op=3, block=290, len=1284
[2026-03-22 21:06:20,938][utils.updater][DEBUG] Successfully uploaded block 290/348
[2026-03-22 21:06:20,938][utils.updater][DEBUG] Successfully uploaded block 291/348
[2026-03-22 21:06:20,939][utils.updater][DEBUG] Received data packet op=3, block=291, len=1284
[2026-03-22 21:06:21,043][utils.updater][DEBUG] Successfully uploaded block 291/348
[2026-03-22 21:06:21,043][utils.updater][DEBUG] Successfully uploaded block 292/348
[2026-03-22 21:06:21,047][utils.updater][DEBUG] Received data packet op=3, block=292, len=1284
[2026-03-22 21:06:21,151][utils.updater][DEBUG] Successfully uploaded block 292/348
[2026-03-22 21:06:21,151][utils.updater][DEBUG] Successfully uploaded block 293/348
[2026-03-22 21:06:21,152][utils.updater][DEBUG] Received data packet op=3, block=293, len=1284
[2026-03-22 21:06:21,256][utils.updater][DEBUG] Successfully uploaded block 293/348
[2026-03-22 21:06:21,256][utils.updater][DEBUG] Successfully uploaded block 294/348
[2026-03-22 21:06:21,257][utils.updater][DEBUG] Received data packet op=3, block=294, len=1284
[2026-03-22 21:06:21,361][utils.updater][DEBUG] Successfully uploaded block 294/348
[2026-03-22 21:06:21,361][utils.updater][DEBUG] Successfully uploaded block 295/348
[2026-03-22 21:06:21,362][utils.updater][DEBUG] Received data packet op=3, block=295, len=1284
[2026-03-22 21:06:21,466][utils.updater][DEBUG] Successfully uploaded block 295/348
[2026-03-22 21:06:21,466][utils.updater][DEBUG] Successfully uploaded block 296/348
[2026-03-22 21:06:21,467][utils.updater][DEBUG] Received data packet op=3, block=296, len=1284
[2026-03-22 21:06:21,571][utils.updater][DEBUG] Successfully uploaded block 296/348
[2026-03-22 21:06:21,571][utils.updater][DEBUG] Successfully uploaded block 297/348
[2026-03-22 21:06:21,572][utils.updater][DEBUG] Received data packet op=3, block=297, len=1284
[2026-03-22 21:06:21,676][utils.updater][DEBUG] Successfully uploaded block 297/348
[2026-03-22 21:06:21,676][utils.updater][DEBUG] Successfully uploaded block 298/348
[2026-03-22 21:06:21,677][utils.updater][DEBUG] Received data packet op=3, block=298, len=1284
[2026-03-22 21:06:21,781][utils.updater][DEBUG] Successfully uploaded block 298/348
[2026-03-22 21:06:21,781][utils.updater][DEBUG] Successfully uploaded block 299/348
[2026-03-22 21:06:21,782][utils.updater][DEBUG] Received data packet op=3, block=299, len=1284
[2026-03-22 21:06:21,886][utils.updater][DEBUG] Successfully uploaded block 299/348
[2026-03-22 21:06:21,886][utils.updater][DEBUG] Successfully uploaded block 300/348
[2026-03-22 21:06:21,887][utils.updater][DEBUG] Received data packet op=3, block=300, len=1284
[2026-03-22 21:06:21,991][utils.updater][DEBUG] Successfully uploaded block 300/348
[2026-03-22 21:06:21,991][utils.updater][DEBUG] Successfully uploaded block 301/348
[2026-03-22 21:06:21,992][utils.updater][DEBUG] Received data packet op=3, block=301, len=1284
[2026-03-22 21:06:22,096][utils.updater][DEBUG] Successfully uploaded block 301/348
[2026-03-22 21:06:22,096][utils.updater][DEBUG] Successfully uploaded block 302/348
[2026-03-22 21:06:22,097][utils.updater][DEBUG] Received data packet op=3, block=302, len=1284
[2026-03-22 21:06:22,201][utils.updater][DEBUG] Successfully uploaded block 302/348
[2026-03-22 21:06:22,201][utils.updater][DEBUG] Successfully uploaded block 303/348
[2026-03-22 21:06:22,202][utils.updater][DEBUG] Received data packet op=3, block=303, len=1284
[2026-03-22 21:06:22,306][utils.updater][DEBUG] Successfully uploaded block 303/348
[2026-03-22 21:06:22,306][utils.updater][DEBUG] Successfully uploaded block 304/348
[2026-03-22 21:06:22,307][utils.updater][DEBUG] Received data packet op=3, block=304, len=1284
[2026-03-22 21:06:22,411][utils.updater][DEBUG] Successfully uploaded block 304/348
[2026-03-22 21:06:22,411][utils.updater][DEBUG] Successfully uploaded block 305/348
[2026-03-22 21:06:22,412][utils.updater][DEBUG] Received data packet op=3, block=305, len=1284
[2026-03-22 21:06:22,516][utils.updater][DEBUG] Successfully uploaded block 305/348
[2026-03-22 21:06:22,516][utils.updater][DEBUG] Successfully uploaded block 306/348
[2026-03-22 21:06:22,517][utils.updater][DEBUG] Received data packet op=3, block=306, len=1284
[2026-03-22 21:06:22,621][utils.updater][DEBUG] Successfully uploaded block 306/348
[2026-03-22 21:06:22,621][utils.updater][DEBUG] Successfully uploaded block 307/348
[2026-03-22 21:06:22,622][utils.updater][DEBUG] Received data packet op=3, block=307, len=1284
[2026-03-22 21:06:22,726][utils.updater][DEBUG] Successfully uploaded block 307/348
[2026-03-22 21:06:22,726][utils.updater][DEBUG] Successfully uploaded block 308/348
[2026-03-22 21:06:22,727][utils.updater][DEBUG] Received data packet op=3, block=308, len=1284
[2026-03-22 21:06:22,831][utils.updater][DEBUG] Successfully uploaded block 308/348
[2026-03-22 21:06:22,831][utils.updater][DEBUG] Successfully uploaded block 309/348
[2026-03-22 21:06:22,832][utils.updater][DEBUG] Received data packet op=3, block=309, len=1284
[2026-03-22 21:06:22,936][utils.updater][DEBUG] Successfully uploaded block 309/348
[2026-03-22 21:06:22,936][utils.updater][DEBUG] Successfully uploaded block 310/348
[2026-03-22 21:06:22,937][utils.updater][DEBUG] Received data packet op=3, block=310, len=1284
[2026-03-22 21:06:23,041][utils.updater][DEBUG] Successfully uploaded block 310/348
[2026-03-22 21:06:23,041][utils.updater][DEBUG] Successfully uploaded block 311/348
[2026-03-22 21:06:23,042][utils.updater][DEBUG] Received data packet op=3, block=311, len=1284
[2026-03-22 21:06:23,149][utils.updater][DEBUG] Successfully uploaded block 311/348
[2026-03-22 21:06:23,149][utils.updater][DEBUG] Successfully uploaded block 312/348
[2026-03-22 21:06:23,150][utils.updater][DEBUG] Received data packet op=3, block=312, len=1284
[2026-03-22 21:06:23,254][utils.updater][DEBUG] Successfully uploaded block 312/348
[2026-03-22 21:06:23,254][utils.updater][DEBUG] Successfully uploaded block 313/348
[2026-03-22 21:06:23,255][utils.updater][DEBUG] Received data packet op=3, block=313, len=1284
[2026-03-22 21:06:23,359][utils.updater][DEBUG] Successfully uploaded block 313/348
[2026-03-22 21:06:23,359][utils.updater][DEBUG] Successfully uploaded block 314/348
[2026-03-22 21:06:23,360][utils.updater][DEBUG] Received data packet op=3, block=314, len=1284
[2026-03-22 21:06:23,464][utils.updater][DEBUG] Successfully uploaded block 314/348
[2026-03-22 21:06:23,464][utils.updater][DEBUG] Successfully uploaded block 315/348
[2026-03-22 21:06:23,465][utils.updater][DEBUG] Received data packet op=3, block=315, len=1284
[2026-03-22 21:06:23,569][utils.updater][DEBUG] Successfully uploaded block 315/348
[2026-03-22 21:06:23,569][utils.updater][DEBUG] Successfully uploaded block 316/348
[2026-03-22 21:06:23,570][utils.updater][DEBUG] Received data packet op=3, block=316, len=1284
[2026-03-22 21:06:23,674][utils.updater][DEBUG] Successfully uploaded block 316/348
[2026-03-22 21:06:23,674][utils.updater][DEBUG] Successfully uploaded block 317/348
[2026-03-22 21:06:23,675][utils.updater][DEBUG] Received data packet op=3, block=317, len=1284
[2026-03-22 21:06:23,780][utils.updater][DEBUG] Successfully uploaded block 317/348
[2026-03-22 21:06:23,780][utils.updater][DEBUG] Successfully uploaded block 318/348
[2026-03-22 21:06:23,781][utils.updater][DEBUG] Received data packet op=3, block=318, len=1284
[2026-03-22 21:06:23,886][utils.updater][DEBUG] Successfully uploaded block 318/348
[2026-03-22 21:06:23,886][utils.updater][DEBUG] Successfully uploaded block 319/348
[2026-03-22 21:06:23,887][utils.updater][DEBUG] Received data packet op=3, block=319, len=1284
[2026-03-22 21:06:23,992][utils.updater][DEBUG] Successfully uploaded block 319/348
[2026-03-22 21:06:23,993][utils.updater][DEBUG] Successfully uploaded block 320/348
[2026-03-22 21:06:23,993][utils.updater][DEBUG] Received data packet op=3, block=320, len=1284
[2026-03-22 21:06:24,098][utils.updater][DEBUG] Successfully uploaded block 320/348
[2026-03-22 21:06:24,098][utils.updater][DEBUG] Successfully uploaded block 321/348
[2026-03-22 21:06:24,099][utils.updater][DEBUG] Received data packet op=3, block=321, len=1284
[2026-03-22 21:06:24,204][utils.updater][DEBUG] Successfully uploaded block 321/348
[2026-03-22 21:06:24,204][utils.updater][DEBUG] Successfully uploaded block 322/348
[2026-03-22 21:06:24,206][utils.updater][DEBUG] Received data packet op=3, block=322, len=1284
[2026-03-22 21:06:24,310][utils.updater][DEBUG] Successfully uploaded block 322/348
[2026-03-22 21:06:24,310][utils.updater][DEBUG] Successfully uploaded block 323/348
[2026-03-22 21:06:24,311][utils.updater][DEBUG] Received data packet op=3, block=323, len=1284
[2026-03-22 21:06:24,415][utils.updater][DEBUG] Successfully uploaded block 323/348
[2026-03-22 21:06:24,415][utils.updater][DEBUG] Successfully uploaded block 324/348
[2026-03-22 21:06:24,416][utils.updater][DEBUG] Received data packet op=3, block=324, len=1284
[2026-03-22 21:06:24,520][utils.updater][DEBUG] Successfully uploaded block 324/348
[2026-03-22 21:06:24,520][utils.updater][DEBUG] Successfully uploaded block 325/348
[2026-03-22 21:06:24,522][utils.updater][DEBUG] Received data packet op=3, block=325, len=1284
[2026-03-22 21:06:24,626][utils.updater][DEBUG] Successfully uploaded block 325/348
[2026-03-22 21:06:24,626][utils.updater][DEBUG] Successfully uploaded block 326/348
[2026-03-22 21:06:24,627][utils.updater][DEBUG] Received data packet op=3, block=326, len=1284
[2026-03-22 21:06:24,732][utils.updater][DEBUG] Successfully uploaded block 326/348
[2026-03-22 21:06:24,732][utils.updater][DEBUG] Successfully uploaded block 327/348
[2026-03-22 21:06:24,733][utils.updater][DEBUG] Received data packet op=3, block=327, len=1284
[2026-03-22 21:06:24,837][utils.updater][DEBUG] Successfully uploaded block 327/348
[2026-03-22 21:06:24,837][utils.updater][DEBUG] Successfully uploaded block 328/348
[2026-03-22 21:06:24,838][utils.updater][DEBUG] Received data packet op=3, block=328, len=1284
[2026-03-22 21:06:24,942][utils.updater][DEBUG] Successfully uploaded block 328/348
[2026-03-22 21:06:24,942][utils.updater][DEBUG] Successfully uploaded block 329/348
[2026-03-22 21:06:24,944][utils.updater][DEBUG] Received data packet op=3, block=329, len=1284
[2026-03-22 21:06:25,048][utils.updater][DEBUG] Successfully uploaded block 329/348
[2026-03-22 21:06:25,048][utils.updater][DEBUG] Successfully uploaded block 330/348
[2026-03-22 21:06:25,049][utils.updater][DEBUG] Received data packet op=3, block=330, len=1284
[2026-03-22 21:06:25,153][utils.updater][DEBUG] Successfully uploaded block 330/348
[2026-03-22 21:06:25,153][utils.updater][DEBUG] Successfully uploaded block 331/348
[2026-03-22 21:06:25,155][utils.updater][DEBUG] Received data packet op=3, block=331, len=1284
[2026-03-22 21:06:25,259][utils.updater][DEBUG] Successfully uploaded block 331/348
[2026-03-22 21:06:25,259][utils.updater][DEBUG] Successfully uploaded block 332/348
[2026-03-22 21:06:25,261][utils.updater][DEBUG] Received data packet op=3, block=332, len=1284
[2026-03-22 21:06:25,366][utils.updater][DEBUG] Successfully uploaded block 332/348
[2026-03-22 21:06:25,366][utils.updater][DEBUG] Successfully uploaded block 333/348
[2026-03-22 21:06:25,367][utils.updater][DEBUG] Received data packet op=3, block=333, len=1284
[2026-03-22 21:06:25,472][utils.updater][DEBUG] Successfully uploaded block 333/348
[2026-03-22 21:06:25,472][utils.updater][DEBUG] Successfully uploaded block 334/348
[2026-03-22 21:06:25,473][utils.updater][DEBUG] Received data packet op=3, block=334, len=1284
[2026-03-22 21:06:25,577][utils.updater][DEBUG] Successfully uploaded block 334/348
[2026-03-22 21:06:25,577][utils.updater][DEBUG] Successfully uploaded block 335/348
[2026-03-22 21:06:25,578][utils.updater][DEBUG] Received data packet op=3, block=335, len=1284
[2026-03-22 21:06:25,682][utils.updater][DEBUG] Successfully uploaded block 335/348
[2026-03-22 21:06:25,682][utils.updater][DEBUG] Successfully uploaded block 336/348
[2026-03-22 21:06:25,683][utils.updater][DEBUG] Received data packet op=3, block=336, len=1284
[2026-03-22 21:06:25,787][utils.updater][DEBUG] Successfully uploaded block 336/348
[2026-03-22 21:06:25,787][utils.updater][DEBUG] Successfully uploaded block 337/348
[2026-03-22 21:06:25,788][utils.updater][DEBUG] Received data packet op=3, block=337, len=1284
[2026-03-22 21:06:25,892][utils.updater][DEBUG] Successfully uploaded block 337/348
[2026-03-22 21:06:25,892][utils.updater][DEBUG] Successfully uploaded block 338/348
[2026-03-22 21:06:25,893][utils.updater][DEBUG] Received data packet op=3, block=338, len=1284
[2026-03-22 21:06:25,997][utils.updater][DEBUG] Successfully uploaded block 338/348
[2026-03-22 21:06:25,997][utils.updater][DEBUG] Successfully uploaded block 339/348
[2026-03-22 21:06:25,998][utils.updater][DEBUG] Received data packet op=3, block=339, len=1284
[2026-03-22 21:06:26,102][utils.updater][DEBUG] Successfully uploaded block 339/348
[2026-03-22 21:06:26,102][utils.updater][DEBUG] Successfully uploaded block 340/348
[2026-03-22 21:06:26,103][utils.updater][DEBUG] Received data packet op=3, block=340, len=1284
[2026-03-22 21:06:26,207][utils.updater][DEBUG] Successfully uploaded block 340/348
[2026-03-22 21:06:26,207][utils.updater][DEBUG] Successfully uploaded block 341/348
[2026-03-22 21:06:26,208][utils.updater][DEBUG] Received data packet op=3, block=341, len=1284
[2026-03-22 21:06:26,312][utils.updater][DEBUG] Successfully uploaded block 341/348
[2026-03-22 21:06:26,312][utils.updater][DEBUG] Successfully uploaded block 342/348
[2026-03-22 21:06:26,313][utils.updater][DEBUG] Received data packet op=3, block=342, len=1284
[2026-03-22 21:06:26,417][utils.updater][DEBUG] Successfully uploaded block 342/348
[2026-03-22 21:06:26,417][utils.updater][DEBUG] Successfully uploaded block 343/348
[2026-03-22 21:06:26,418][utils.updater][DEBUG] Received data packet op=3, block=343, len=1284
[2026-03-22 21:06:26,522][utils.updater][DEBUG] Successfully uploaded block 343/348
[2026-03-22 21:06:26,522][utils.updater][DEBUG] Successfully uploaded block 344/348
[2026-03-22 21:06:26,523][utils.updater][DEBUG] Received data packet op=3, block=344, len=1284
[2026-03-22 21:06:26,627][utils.updater][DEBUG] Successfully uploaded block 344/348
[2026-03-22 21:06:26,627][utils.updater][DEBUG] Successfully uploaded block 345/348
[2026-03-22 21:06:26,628][utils.updater][DEBUG] Received data packet op=3, block=345, len=1284
[2026-03-22 21:06:26,732][utils.updater][DEBUG] Successfully uploaded block 345/348
[2026-03-22 21:06:26,732][utils.updater][DEBUG] Successfully uploaded block 346/348
[2026-03-22 21:06:26,733][utils.updater][DEBUG] Received data packet op=3, block=346, len=1284
[2026-03-22 21:06:26,838][utils.updater][DEBUG] Successfully uploaded block 346/348
[2026-03-22 21:06:26,838][utils.updater][DEBUG] Successfully uploaded block 347/348
[2026-03-22 21:06:26,839][utils.updater][DEBUG] Received data packet op=3, block=347, len=1284
[2026-03-22 21:06:26,944][utils.updater][DEBUG] Successfully uploaded block 347/348
[2026-03-22 21:06:26,944][tftpy.TftpStates][DEBUG] Reached EOF on file BaseBoard.bin
[2026-03-22 21:06:26,944][utils.updater][DEBUG] Successfully uploaded block 348/348
[2026-03-22 21:06:26,945][utils.updater][DEBUG] Received data packet op=3, block=348, len=260
[2026-03-22 21:06:27,046][utils.updater][DEBUG] Successfully uploaded block 348/348
[2026-03-22 21:06:27,046][tftpy.TftpStates][DEBUG] Received ACK to final DAT, we're done.
[2026-03-22 21:06:27,047][tftpy.TftpClient][DEBUG]
[2026-03-22 21:06:27,047][tftpy.TftpClient][DEBUG] Upload complete.
[2026-03-22 21:06:27,047][tftpy.TftpClient][DEBUG] Uploaded 444416 bytes in 36.86 seconds
[2026-03-22 21:06:27,047][utils.updater][DEBUG] Total bytes Received: 444416 bytes
[2026-03-22 21:06:27,047][tftpy.TftpClient][DEBUG] Average rate: 94.20 kbps
[2026-03-22 21:06:27,047][tftpy.TftpClient][DEBUG] 0.00 bytes in resent data
[2026-03-22 21:06:27,047][utils.updater][DEBUG] State: Download Finished
[2026-03-22 21:06:27,047][tftpy.TftpClient][DEBUG] Resent 0 packets
[2026-03-22 21:06:27,048][utils.updater][DEBUG] Upload Complete
[2026-03-22 21:06:27,919][utils.updater][DEBUG] OTA Update OK
[2026-03-22 21:06:27,920][utils.updater][DEBUG] Update will occur on reboot.
[2026-03-22 21:06:27,920][utils.updater][DEBUG] System will reset in 5 sec.
[2026-03-22 21:06:27,920][root][INFO] Image upload was successful
[2026-03-22 21:06:27,920][root][INFO] Waiting 10 seconds before sending ping...
[2026-03-22 21:06:37,930][root][INFO] Waiting up to 60.0 seconds for Baseboard connectivity...
[2026-03-22 21:07:23,016][root][INFO] Restart and flash complete. Waiting 10 sec for baseboard to initialize.
[2026-03-22 21:07:33,023][root][INFO] Initialization complete.
[2026-03-22 21:07:33,023][root][INFO] Flashing motor (Motor (3.4.0.2) >>>> Motor (3.4.1.3))
[2026-03-22 21:07:33,023][root][INFO] Waiting 20 seconds for motor board to initialize
[2026-03-22 21:07:53,043][utils.updater][DEBUG] Updater starting with requested options: {'blksize': 1280}

[2026-03-22 21:07:53,044][utils.updater][DEBUG] sending file binaries/Aethon/BearDriver.txt

[2026-03-22 21:07:53,044][utils.updater][DEBUG] file length: 245686

[2026-03-22 21:07:53,491][utils.updater][DEBUG] file crc: 1908628488

[2026-03-22 21:07:53,535][utils.updater][DEBUG] Asking baseboard to start OTA task...
[2026-03-22 21:07:55,038][utils.updater][DEBUG] TFTP server initialized
[2026-03-22 21:07:55,038][utils.updater][DEBUG] Starting TFTP upload attempt
[2026-03-22 21:07:55,038][utils.updater][DEBUG] Checking upload status
[2026-03-22 21:07:55,038][utils.updater][DEBUG] Tftpy client connected.
[2026-03-22 21:07:55,039][utils.updater][DEBUG] Starting upload of binaries/Aethon/BearDriver.txt
[2026-03-22 21:07:55,039][tftpy.TftpContext][DEBUG] Sending tftp upload request to 10.2.98.200
[2026-03-22 21:07:55,039][tftpy.TftpContext][DEBUG]     filename -> BearDriver.txt
[2026-03-22 21:07:55,039][tftpy.TftpContext][DEBUG]     options -> {'blksize': 1280}
[2026-03-22 21:07:55,040][utils.updater][DEBUG] TFTP download request received.
[2026-03-22 21:07:55,040][utils.updater][DEBUG] State: Downloading...
[2026-03-22 21:07:55,140][tftpy.TftpStates][DEBUG] Received OACK from server
[2026-03-22 21:07:55,140][tftpy.TftpStates][DEBUG] Successful negotiation of options
[2026-03-22 21:07:55,140][tftpy.TftpStates][DEBUG]     blksize = 1280
[2026-03-22 21:07:55,140][utils.updater][DEBUG] Successfully uploaded block 1/192
[2026-03-22 21:07:55,141][utils.updater][DEBUG] Received data packet op=3, block=1, len=1284
[2026-03-22 21:07:55,245][utils.updater][DEBUG] Successfully uploaded block 1/192
[2026-03-22 21:07:55,246][utils.updater][DEBUG] Successfully uploaded block 2/192
[2026-03-22 21:07:55,246][utils.updater][DEBUG] Received data packet op=3, block=2, len=1284
[2026-03-22 21:07:55,351][utils.updater][DEBUG] Successfully uploaded block 2/192
[2026-03-22 21:07:55,351][utils.updater][DEBUG] Successfully uploaded block 3/192
[2026-03-22 21:07:55,351][utils.updater][DEBUG] Received data packet op=3, block=3, len=1284
[2026-03-22 21:07:55,455][utils.updater][DEBUG] Successfully uploaded block 3/192
[2026-03-22 21:07:55,456][utils.updater][DEBUG] Successfully uploaded block 4/192
[2026-03-22 21:07:55,456][utils.updater][DEBUG] Received data packet op=3, block=4, len=1284
[2026-03-22 21:07:55,560][utils.updater][DEBUG] Successfully uploaded block 4/192
[2026-03-22 21:07:55,561][utils.updater][DEBUG] Successfully uploaded block 5/192
[2026-03-22 21:07:55,561][utils.updater][DEBUG] Received data packet op=3, block=5, len=1284
[2026-03-22 21:07:55,665][utils.updater][DEBUG] Successfully uploaded block 5/192
[2026-03-22 21:07:55,666][utils.updater][DEBUG] Successfully uploaded block 6/192
[2026-03-22 21:07:55,666][utils.updater][DEBUG] Received data packet op=3, block=6, len=1284
[2026-03-22 21:07:55,770][utils.updater][DEBUG] Successfully uploaded block 6/192
[2026-03-22 21:07:55,771][utils.updater][DEBUG] Successfully uploaded block 7/192
[2026-03-22 21:07:55,771][utils.updater][DEBUG] Received data packet op=3, block=7, len=1284
[2026-03-22 21:07:55,876][utils.updater][DEBUG] Successfully uploaded block 7/192
[2026-03-22 21:07:55,876][utils.updater][DEBUG] Successfully uploaded block 8/192
[2026-03-22 21:07:55,876][utils.updater][DEBUG] Received data packet op=3, block=8, len=1284
[2026-03-22 21:07:55,980][utils.updater][DEBUG] Successfully uploaded block 8/192
[2026-03-22 21:07:55,981][utils.updater][DEBUG] Successfully uploaded block 9/192
[2026-03-22 21:07:55,981][utils.updater][DEBUG] Received data packet op=3, block=9, len=1284
[2026-03-22 21:07:56,086][utils.updater][DEBUG] Successfully uploaded block 9/192
[2026-03-22 21:07:56,086][utils.updater][DEBUG] Successfully uploaded block 10/192
[2026-03-22 21:07:56,086][utils.updater][DEBUG] Received data packet op=3, block=10, len=1284
[2026-03-22 21:07:56,190][utils.updater][DEBUG] Successfully uploaded block 10/192
[2026-03-22 21:07:56,191][utils.updater][DEBUG] Successfully uploaded block 11/192
[2026-03-22 21:07:56,191][utils.updater][DEBUG] Received data packet op=3, block=11, len=1284
[2026-03-22 21:07:56,295][utils.updater][DEBUG] Successfully uploaded block 11/192
[2026-03-22 21:07:56,296][utils.updater][DEBUG] Successfully uploaded block 12/192
[2026-03-22 21:07:56,296][utils.updater][DEBUG] Received data packet op=3, block=12, len=1284
[2026-03-22 21:07:56,401][utils.updater][DEBUG] Successfully uploaded block 12/192
[2026-03-22 21:07:56,401][utils.updater][DEBUG] Successfully uploaded block 13/192
[2026-03-22 21:07:56,401][utils.updater][DEBUG] Received data packet op=3, block=13, len=1284
[2026-03-22 21:07:56,505][utils.updater][DEBUG] Successfully uploaded block 13/192
[2026-03-22 21:07:56,506][utils.updater][DEBUG] Successfully uploaded block 14/192
[2026-03-22 21:07:56,506][utils.updater][DEBUG] Received data packet op=3, block=14, len=1284
[2026-03-22 21:07:56,610][utils.updater][DEBUG] Successfully uploaded block 14/192
[2026-03-22 21:07:56,611][utils.updater][DEBUG] Successfully uploaded block 15/192
[2026-03-22 21:07:56,611][utils.updater][DEBUG] Received data packet op=3, block=15, len=1284
[2026-03-22 21:07:56,716][utils.updater][DEBUG] Successfully uploaded block 15/192
[2026-03-22 21:07:56,716][utils.updater][DEBUG] Successfully uploaded block 16/192
[2026-03-22 21:07:56,716][utils.updater][DEBUG] Received data packet op=3, block=16, len=1284
[2026-03-22 21:07:56,820][utils.updater][DEBUG] Successfully uploaded block 16/192
[2026-03-22 21:07:56,821][utils.updater][DEBUG] Successfully uploaded block 17/192
[2026-03-22 21:07:56,821][utils.updater][DEBUG] Received data packet op=3, block=17, len=1284
[2026-03-22 21:07:56,926][utils.updater][DEBUG] Successfully uploaded block 17/192
[2026-03-22 21:07:56,926][utils.updater][DEBUG] Successfully uploaded block 18/192
[2026-03-22 21:07:56,926][utils.updater][DEBUG] Received data packet op=3, block=18, len=1284
[2026-03-22 21:07:57,033][utils.updater][DEBUG] Successfully uploaded block 18/192
[2026-03-22 21:07:57,033][utils.updater][DEBUG] Successfully uploaded block 19/192
[2026-03-22 21:07:57,033][utils.updater][DEBUG] Received data packet op=3, block=19, len=1284
[2026-03-22 21:07:57,138][utils.updater][DEBUG] Successfully uploaded block 19/192
[2026-03-22 21:07:57,138][utils.updater][DEBUG] Successfully uploaded block 20/192
[2026-03-22 21:07:57,138][utils.updater][DEBUG] Received data packet op=3, block=20, len=1284
[2026-03-22 21:07:57,242][utils.updater][DEBUG] Successfully uploaded block 20/192
[2026-03-22 21:07:57,243][utils.updater][DEBUG] Successfully uploaded block 21/192
[2026-03-22 21:07:57,243][utils.updater][DEBUG] Received data packet op=3, block=21, len=1284
[2026-03-22 21:07:57,347][utils.updater][DEBUG] Successfully uploaded block 21/192
[2026-03-22 21:07:57,348][utils.updater][DEBUG] Successfully uploaded block 22/192
[2026-03-22 21:07:57,348][utils.updater][DEBUG] Received data packet op=3, block=22, len=1284
[2026-03-22 21:07:57,452][utils.updater][DEBUG] Successfully uploaded block 22/192
[2026-03-22 21:07:57,453][utils.updater][DEBUG] Successfully uploaded block 23/192
[2026-03-22 21:07:57,453][utils.updater][DEBUG] Received data packet op=3, block=23, len=1284
[2026-03-22 21:07:57,558][utils.updater][DEBUG] Successfully uploaded block 23/192
[2026-03-22 21:07:57,558][utils.updater][DEBUG] Successfully uploaded block 24/192
[2026-03-22 21:07:57,558][utils.updater][DEBUG] Received data packet op=3, block=24, len=1284
[2026-03-22 21:07:57,662][utils.updater][DEBUG] Successfully uploaded block 24/192
[2026-03-22 21:07:57,663][utils.updater][DEBUG] Successfully uploaded block 25/192
[2026-03-22 21:07:57,663][utils.updater][DEBUG] Received data packet op=3, block=25, len=1284
[2026-03-22 21:07:57,768][utils.updater][DEBUG] Successfully uploaded block 25/192
[2026-03-22 21:07:57,768][utils.updater][DEBUG] Successfully uploaded block 26/192
[2026-03-22 21:07:57,768][utils.updater][DEBUG] Received data packet op=3, block=26, len=1284
[2026-03-22 21:07:57,872][utils.updater][DEBUG] Successfully uploaded block 26/192
[2026-03-22 21:07:57,873][utils.updater][DEBUG] Successfully uploaded block 27/192
[2026-03-22 21:07:57,873][utils.updater][DEBUG] Received data packet op=3, block=27, len=1284
[2026-03-22 21:07:57,978][utils.updater][DEBUG] Successfully uploaded block 27/192
[2026-03-22 21:07:57,978][utils.updater][DEBUG] Successfully uploaded block 28/192
[2026-03-22 21:07:57,978][utils.updater][DEBUG] Received data packet op=3, block=28, len=1284
[2026-03-22 21:07:58,083][utils.updater][DEBUG] Successfully uploaded block 28/192
[2026-03-22 21:07:58,083][utils.updater][DEBUG] Successfully uploaded block 29/192
[2026-03-22 21:07:58,083][utils.updater][DEBUG] Received data packet op=3, block=29, len=1284
[2026-03-22 21:07:58,188][utils.updater][DEBUG] Successfully uploaded block 29/192
[2026-03-22 21:07:58,188][utils.updater][DEBUG] Successfully uploaded block 30/192
[2026-03-22 21:07:58,188][utils.updater][DEBUG] Received data packet op=3, block=30, len=1284
[2026-03-22 21:07:58,293][utils.updater][DEBUG] Successfully uploaded block 30/192
[2026-03-22 21:07:58,293][utils.updater][DEBUG] Successfully uploaded block 31/192
[2026-03-22 21:07:58,293][utils.updater][DEBUG] Received data packet op=3, block=31, len=1284
[2026-03-22 21:07:58,398][utils.updater][DEBUG] Successfully uploaded block 31/192
[2026-03-22 21:07:58,398][utils.updater][DEBUG] Successfully uploaded block 32/192
[2026-03-22 21:07:58,398][utils.updater][DEBUG] Received data packet op=3, block=32, len=1284
[2026-03-22 21:07:58,503][utils.updater][DEBUG] Successfully uploaded block 32/192
[2026-03-22 21:07:58,503][utils.updater][DEBUG] Successfully uploaded block 33/192
[2026-03-22 21:07:58,503][utils.updater][DEBUG] Received data packet op=3, block=33, len=1284
[2026-03-22 21:07:58,608][utils.updater][DEBUG] Successfully uploaded block 33/192
[2026-03-22 21:07:58,608][utils.updater][DEBUG] Successfully uploaded block 34/192
[2026-03-22 21:07:58,608][utils.updater][DEBUG] Received data packet op=3, block=34, len=1284
[2026-03-22 21:07:58,713][utils.updater][DEBUG] Successfully uploaded block 34/192
[2026-03-22 21:07:58,713][utils.updater][DEBUG] Successfully uploaded block 35/192
[2026-03-22 21:07:58,713][utils.updater][DEBUG] Received data packet op=3, block=35, len=1284
[2026-03-22 21:07:58,818][utils.updater][DEBUG] Successfully uploaded block 35/192
[2026-03-22 21:07:58,818][utils.updater][DEBUG] Successfully uploaded block 36/192
[2026-03-22 21:07:58,818][utils.updater][DEBUG] Received data packet op=3, block=36, len=1284
[2026-03-22 21:07:58,923][utils.updater][DEBUG] Successfully uploaded block 36/192
[2026-03-22 21:07:58,923][utils.updater][DEBUG] Successfully uploaded block 37/192
[2026-03-22 21:07:58,923][utils.updater][DEBUG] Received data packet op=3, block=37, len=1284
[2026-03-22 21:07:59,028][utils.updater][DEBUG] Successfully uploaded block 37/192
[2026-03-22 21:07:59,028][utils.updater][DEBUG] Successfully uploaded block 38/192
[2026-03-22 21:07:59,028][utils.updater][DEBUG] Received data packet op=3, block=38, len=1284
[2026-03-22 21:07:59,136][utils.updater][DEBUG] Successfully uploaded block 38/192
[2026-03-22 21:07:59,136][utils.updater][DEBUG] Successfully uploaded block 39/192
[2026-03-22 21:07:59,136][utils.updater][DEBUG] Received data packet op=3, block=39, len=1284
[2026-03-22 21:07:59,241][utils.updater][DEBUG] Successfully uploaded block 39/192
[2026-03-22 21:07:59,241][utils.updater][DEBUG] Successfully uploaded block 40/192
[2026-03-22 21:07:59,241][utils.updater][DEBUG] Received data packet op=3, block=40, len=1284
[2026-03-22 21:07:59,346][utils.updater][DEBUG] Successfully uploaded block 40/192
[2026-03-22 21:07:59,346][utils.updater][DEBUG] Successfully uploaded block 41/192
[2026-03-22 21:07:59,346][utils.updater][DEBUG] Received data packet op=3, block=41, len=1284
[2026-03-22 21:07:59,451][utils.updater][DEBUG] Successfully uploaded block 41/192
[2026-03-22 21:07:59,451][utils.updater][DEBUG] Successfully uploaded block 42/192
[2026-03-22 21:07:59,451][utils.updater][DEBUG] Received data packet op=3, block=42, len=1284
[2026-03-22 21:07:59,556][utils.updater][DEBUG] Successfully uploaded block 42/192
[2026-03-22 21:07:59,556][utils.updater][DEBUG] Successfully uploaded block 43/192
[2026-03-22 21:07:59,556][utils.updater][DEBUG] Received data packet op=3, block=43, len=1284
[2026-03-22 21:07:59,661][utils.updater][DEBUG] Successfully uploaded block 43/192
[2026-03-22 21:07:59,661][utils.updater][DEBUG] Successfully uploaded block 44/192
[2026-03-22 21:07:59,661][utils.updater][DEBUG] Received data packet op=3, block=44, len=1284
[2026-03-22 21:07:59,766][utils.updater][DEBUG] Successfully uploaded block 44/192
[2026-03-22 21:07:59,766][utils.updater][DEBUG] Successfully uploaded block 45/192
[2026-03-22 21:07:59,766][utils.updater][DEBUG] Received data packet op=3, block=45, len=1284
[2026-03-22 21:07:59,871][utils.updater][DEBUG] Successfully uploaded block 45/192
[2026-03-22 21:07:59,871][utils.updater][DEBUG] Successfully uploaded block 46/192
[2026-03-22 21:07:59,871][utils.updater][DEBUG] Received data packet op=3, block=46, len=1284
[2026-03-22 21:07:59,976][utils.updater][DEBUG] Successfully uploaded block 46/192
[2026-03-22 21:07:59,976][utils.updater][DEBUG] Successfully uploaded block 47/192
[2026-03-22 21:07:59,976][utils.updater][DEBUG] Received data packet op=3, block=47, len=1284
[2026-03-22 21:08:00,081][utils.updater][DEBUG] Successfully uploaded block 47/192
[2026-03-22 21:08:00,081][utils.updater][DEBUG] Successfully uploaded block 48/192
[2026-03-22 21:08:00,081][utils.updater][DEBUG] Received data packet op=3, block=48, len=1284
[2026-03-22 21:08:00,186][utils.updater][DEBUG] Successfully uploaded block 48/192
[2026-03-22 21:08:00,186][utils.updater][DEBUG] Successfully uploaded block 49/192
[2026-03-22 21:08:00,186][utils.updater][DEBUG] Received data packet op=3, block=49, len=1284
[2026-03-22 21:08:00,291][utils.updater][DEBUG] Successfully uploaded block 49/192
[2026-03-22 21:08:00,291][utils.updater][DEBUG] Successfully uploaded block 50/192
[2026-03-22 21:08:00,291][utils.updater][DEBUG] Received data packet op=3, block=50, len=1284
[2026-03-22 21:08:00,396][utils.updater][DEBUG] Successfully uploaded block 50/192
[2026-03-22 21:08:00,396][utils.updater][DEBUG] Successfully uploaded block 51/192
[2026-03-22 21:08:00,396][utils.updater][DEBUG] Received data packet op=3, block=51, len=1284
[2026-03-22 21:08:00,501][utils.updater][DEBUG] Successfully uploaded block 51/192
[2026-03-22 21:08:00,501][utils.updater][DEBUG] Successfully uploaded block 52/192
[2026-03-22 21:08:00,501][utils.updater][DEBUG] Received data packet op=3, block=52, len=1284
[2026-03-22 21:08:00,606][utils.updater][DEBUG] Successfully uploaded block 52/192
[2026-03-22 21:08:00,606][utils.updater][DEBUG] Successfully uploaded block 53/192
[2026-03-22 21:08:00,606][utils.updater][DEBUG] Received data packet op=3, block=53, len=1284
[2026-03-22 21:08:00,711][utils.updater][DEBUG] Successfully uploaded block 53/192
[2026-03-22 21:08:00,711][utils.updater][DEBUG] Successfully uploaded block 54/192
[2026-03-22 21:08:00,711][utils.updater][DEBUG] Received data packet op=3, block=54, len=1284
[2026-03-22 21:08:00,816][utils.updater][DEBUG] Successfully uploaded block 54/192
[2026-03-22 21:08:00,816][utils.updater][DEBUG] Successfully uploaded block 55/192
[2026-03-22 21:08:00,816][utils.updater][DEBUG] Received data packet op=3, block=55, len=1284
[2026-03-22 21:08:00,921][utils.updater][DEBUG] Successfully uploaded block 55/192
[2026-03-22 21:08:00,921][utils.updater][DEBUG] Successfully uploaded block 56/192
[2026-03-22 21:08:00,921][utils.updater][DEBUG] Received data packet op=3, block=56, len=1284
[2026-03-22 21:08:01,026][utils.updater][DEBUG] Successfully uploaded block 56/192
[2026-03-22 21:08:01,026][utils.updater][DEBUG] Successfully uploaded block 57/192
[2026-03-22 21:08:01,026][utils.updater][DEBUG] Received data packet op=3, block=57, len=1284
[2026-03-22 21:08:01,133][utils.updater][DEBUG] Successfully uploaded block 57/192
[2026-03-22 21:08:01,133][utils.updater][DEBUG] Successfully uploaded block 58/192
[2026-03-22 21:08:01,133][utils.updater][DEBUG] Received data packet op=3, block=58, len=1284
[2026-03-22 21:08:01,238][utils.updater][DEBUG] Successfully uploaded block 58/192
[2026-03-22 21:08:01,238][utils.updater][DEBUG] Successfully uploaded block 59/192
[2026-03-22 21:08:01,238][utils.updater][DEBUG] Received data packet op=3, block=59, len=1284
[2026-03-22 21:08:01,343][utils.updater][DEBUG] Successfully uploaded block 59/192
[2026-03-22 21:08:01,343][utils.updater][DEBUG] Successfully uploaded block 60/192
[2026-03-22 21:08:01,343][utils.updater][DEBUG] Received data packet op=3, block=60, len=1284
[2026-03-22 21:08:01,448][utils.updater][DEBUG] Successfully uploaded block 60/192
[2026-03-22 21:08:01,448][utils.updater][DEBUG] Successfully uploaded block 61/192
[2026-03-22 21:08:01,448][utils.updater][DEBUG] Received data packet op=3, block=61, len=1284
[2026-03-22 21:08:01,553][utils.updater][DEBUG] Successfully uploaded block 61/192
[2026-03-22 21:08:01,553][utils.updater][DEBUG] Successfully uploaded block 62/192
[2026-03-22 21:08:01,553][utils.updater][DEBUG] Received data packet op=3, block=62, len=1284
[2026-03-22 21:08:01,658][utils.updater][DEBUG] Successfully uploaded block 62/192
[2026-03-22 21:08:01,658][utils.updater][DEBUG] Successfully uploaded block 63/192
[2026-03-22 21:08:01,658][utils.updater][DEBUG] Received data packet op=3, block=63, len=1284
[2026-03-22 21:08:01,762][utils.updater][DEBUG] Successfully uploaded block 63/192
[2026-03-22 21:08:01,763][utils.updater][DEBUG] Successfully uploaded block 64/192
[2026-03-22 21:08:01,763][utils.updater][DEBUG] Received data packet op=3, block=64, len=1284
[2026-03-22 21:08:01,867][utils.updater][DEBUG] Successfully uploaded block 64/192
[2026-03-22 21:08:01,868][utils.updater][DEBUG] Successfully uploaded block 65/192
[2026-03-22 21:08:01,868][utils.updater][DEBUG] Received data packet op=3, block=65, len=1284
[2026-03-22 21:08:01,972][utils.updater][DEBUG] Successfully uploaded block 65/192
[2026-03-22 21:08:01,973][utils.updater][DEBUG] Successfully uploaded block 66/192
[2026-03-22 21:08:01,973][utils.updater][DEBUG] Received data packet op=3, block=66, len=1284
[2026-03-22 21:08:02,078][utils.updater][DEBUG] Successfully uploaded block 66/192
[2026-03-22 21:08:02,078][utils.updater][DEBUG] Successfully uploaded block 67/192
[2026-03-22 21:08:02,078][utils.updater][DEBUG] Received data packet op=3, block=67, len=1284
[2026-03-22 21:08:02,183][utils.updater][DEBUG] Successfully uploaded block 67/192
[2026-03-22 21:08:02,183][utils.updater][DEBUG] Successfully uploaded block 68/192
[2026-03-22 21:08:02,183][utils.updater][DEBUG] Received data packet op=3, block=68, len=1284
[2026-03-22 21:08:02,288][utils.updater][DEBUG] Successfully uploaded block 68/192
[2026-03-22 21:08:02,288][utils.updater][DEBUG] Successfully uploaded block 69/192
[2026-03-22 21:08:02,288][utils.updater][DEBUG] Received data packet op=3, block=69, len=1284
[2026-03-22 21:08:02,393][utils.updater][DEBUG] Successfully uploaded block 69/192
[2026-03-22 21:08:02,393][utils.updater][DEBUG] Successfully uploaded block 70/192
[2026-03-22 21:08:02,393][utils.updater][DEBUG] Received data packet op=3, block=70, len=1284
[2026-03-22 21:08:02,498][utils.updater][DEBUG] Successfully uploaded block 70/192
[2026-03-22 21:08:02,498][utils.updater][DEBUG] Successfully uploaded block 71/192
[2026-03-22 21:08:02,498][utils.updater][DEBUG] Received data packet op=3, block=71, len=1284
[2026-03-22 21:08:02,603][utils.updater][DEBUG] Successfully uploaded block 71/192
[2026-03-22 21:08:02,603][utils.updater][DEBUG] Successfully uploaded block 72/192
[2026-03-22 21:08:02,603][utils.updater][DEBUG] Received data packet op=3, block=72, len=1284
[2026-03-22 21:08:02,708][utils.updater][DEBUG] Successfully uploaded block 72/192
[2026-03-22 21:08:02,708][utils.updater][DEBUG] Successfully uploaded block 73/192
[2026-03-22 21:08:02,708][utils.updater][DEBUG] Received data packet op=3, block=73, len=1284
[2026-03-22 21:08:02,813][utils.updater][DEBUG] Successfully uploaded block 73/192
[2026-03-22 21:08:02,813][utils.updater][DEBUG] Successfully uploaded block 74/192
[2026-03-22 21:08:02,813][utils.updater][DEBUG] Received data packet op=3, block=74, len=1284
[2026-03-22 21:08:02,918][utils.updater][DEBUG] Successfully uploaded block 74/192
[2026-03-22 21:08:02,918][utils.updater][DEBUG] Successfully uploaded block 75/192
[2026-03-22 21:08:02,918][utils.updater][DEBUG] Received data packet op=3, block=75, len=1284
[2026-03-22 21:08:03,023][utils.updater][DEBUG] Successfully uploaded block 75/192
[2026-03-22 21:08:03,023][utils.updater][DEBUG] Successfully uploaded block 76/192
[2026-03-22 21:08:03,023][utils.updater][DEBUG] Received data packet op=3, block=76, len=1284
[2026-03-22 21:08:03,128][utils.updater][DEBUG] Successfully uploaded block 76/192
[2026-03-22 21:08:03,128][utils.updater][DEBUG] Successfully uploaded block 77/192
[2026-03-22 21:08:03,128][utils.updater][DEBUG] Received data packet op=3, block=77, len=1284
[2026-03-22 21:08:03,233][utils.updater][DEBUG] Successfully uploaded block 77/192
[2026-03-22 21:08:03,233][utils.updater][DEBUG] Successfully uploaded block 78/192
[2026-03-22 21:08:03,233][utils.updater][DEBUG] Received data packet op=3, block=78, len=1284
[2026-03-22 21:08:03,338][utils.updater][DEBUG] Successfully uploaded block 78/192
[2026-03-22 21:08:03,338][utils.updater][DEBUG] Successfully uploaded block 79/192
[2026-03-22 21:08:03,338][utils.updater][DEBUG] Received data packet op=3, block=79, len=1284
[2026-03-22 21:08:03,443][utils.updater][DEBUG] Successfully uploaded block 79/192
[2026-03-22 21:08:03,443][utils.updater][DEBUG] Successfully uploaded block 80/192
[2026-03-22 21:08:03,443][utils.updater][DEBUG] Received data packet op=3, block=80, len=1284
[2026-03-22 21:08:03,548][utils.updater][DEBUG] Successfully uploaded block 80/192
[2026-03-22 21:08:03,548][utils.updater][DEBUG] Successfully uploaded block 81/192
[2026-03-22 21:08:03,548][utils.updater][DEBUG] Received data packet op=3, block=81, len=1284
[2026-03-22 21:08:03,653][utils.updater][DEBUG] Successfully uploaded block 81/192
[2026-03-22 21:08:03,653][utils.updater][DEBUG] Successfully uploaded block 82/192
[2026-03-22 21:08:03,653][utils.updater][DEBUG] Received data packet op=3, block=82, len=1284
[2026-03-22 21:08:03,758][utils.updater][DEBUG] Successfully uploaded block 82/192
[2026-03-22 21:08:03,758][utils.updater][DEBUG] Successfully uploaded block 83/192
[2026-03-22 21:08:03,758][utils.updater][DEBUG] Received data packet op=3, block=83, len=1284
[2026-03-22 21:08:03,863][utils.updater][DEBUG] Successfully uploaded block 83/192
[2026-03-22 21:08:03,863][utils.updater][DEBUG] Successfully uploaded block 84/192
[2026-03-22 21:08:03,863][utils.updater][DEBUG] Received data packet op=3, block=84, len=1284
[2026-03-22 21:08:03,968][utils.updater][DEBUG] Successfully uploaded block 84/192
[2026-03-22 21:08:03,968][utils.updater][DEBUG] Successfully uploaded block 85/192
[2026-03-22 21:08:03,968][utils.updater][DEBUG] Received data packet op=3, block=85, len=1284
[2026-03-22 21:08:04,073][utils.updater][DEBUG] Successfully uploaded block 85/192
[2026-03-22 21:08:04,073][utils.updater][DEBUG] Successfully uploaded block 86/192
[2026-03-22 21:08:04,073][utils.updater][DEBUG] Received data packet op=3, block=86, len=1284
[2026-03-22 21:08:04,178][utils.updater][DEBUG] Successfully uploaded block 86/192
[2026-03-22 21:08:04,178][utils.updater][DEBUG] Successfully uploaded block 87/192
[2026-03-22 21:08:04,178][utils.updater][DEBUG] Received data packet op=3, block=87, len=1284
[2026-03-22 21:08:04,282][utils.updater][DEBUG] Successfully uploaded block 87/192
[2026-03-22 21:08:04,283][utils.updater][DEBUG] Successfully uploaded block 88/192
[2026-03-22 21:08:04,283][utils.updater][DEBUG] Received data packet op=3, block=88, len=1284
[2026-03-22 21:08:04,388][utils.updater][DEBUG] Successfully uploaded block 88/192
[2026-03-22 21:08:04,388][utils.updater][DEBUG] Successfully uploaded block 89/192
[2026-03-22 21:08:04,388][utils.updater][DEBUG] Received data packet op=3, block=89, len=1284
[2026-03-22 21:08:04,492][utils.updater][DEBUG] Successfully uploaded block 89/192
[2026-03-22 21:08:04,493][utils.updater][DEBUG] Successfully uploaded block 90/192
[2026-03-22 21:08:04,493][utils.updater][DEBUG] Received data packet op=3, block=90, len=1284
[2026-03-22 21:08:04,598][utils.updater][DEBUG] Successfully uploaded block 90/192
[2026-03-22 21:08:04,598][utils.updater][DEBUG] Successfully uploaded block 91/192
[2026-03-22 21:08:04,598][utils.updater][DEBUG] Received data packet op=3, block=91, len=1284
[2026-03-22 21:08:04,702][utils.updater][DEBUG] Successfully uploaded block 91/192
[2026-03-22 21:08:04,703][utils.updater][DEBUG] Successfully uploaded block 92/192
[2026-03-22 21:08:04,703][utils.updater][DEBUG] Received data packet op=3, block=92, len=1284
[2026-03-22 21:08:04,808][utils.updater][DEBUG] Successfully uploaded block 92/192
[2026-03-22 21:08:04,808][utils.updater][DEBUG] Successfully uploaded block 93/192
[2026-03-22 21:08:04,808][utils.updater][DEBUG] Received data packet op=3, block=93, len=1284
[2026-03-22 21:08:04,912][utils.updater][DEBUG] Successfully uploaded block 93/192
[2026-03-22 21:08:04,913][utils.updater][DEBUG] Successfully uploaded block 94/192
[2026-03-22 21:08:04,913][utils.updater][DEBUG] Received data packet op=3, block=94, len=1284
[2026-03-22 21:08:05,018][utils.updater][DEBUG] Successfully uploaded block 94/192
[2026-03-22 21:08:05,018][utils.updater][DEBUG] Successfully uploaded block 95/192
[2026-03-22 21:08:05,018][utils.updater][DEBUG] Received data packet op=3, block=95, len=1284
[2026-03-22 21:08:05,122][utils.updater][DEBUG] Successfully uploaded block 95/192
[2026-03-22 21:08:05,123][utils.updater][DEBUG] Successfully uploaded block 96/192
[2026-03-22 21:08:05,123][utils.updater][DEBUG] Received data packet op=3, block=96, len=1284
[2026-03-22 21:08:05,228][utils.updater][DEBUG] Successfully uploaded block 96/192
[2026-03-22 21:08:05,228][utils.updater][DEBUG] Successfully uploaded block 97/192
[2026-03-22 21:08:05,228][utils.updater][DEBUG] Received data packet op=3, block=97, len=1284
[2026-03-22 21:08:05,333][utils.updater][DEBUG] Successfully uploaded block 97/192
[2026-03-22 21:08:05,333][utils.updater][DEBUG] Successfully uploaded block 98/192
[2026-03-22 21:08:05,333][utils.updater][DEBUG] Received data packet op=3, block=98, len=1284
[2026-03-22 21:08:05,438][utils.updater][DEBUG] Successfully uploaded block 98/192
[2026-03-22 21:08:05,438][utils.updater][DEBUG] Successfully uploaded block 99/192
[2026-03-22 21:08:05,438][utils.updater][DEBUG] Received data packet op=3, block=99, len=1284
[2026-03-22 21:08:05,543][utils.updater][DEBUG] Successfully uploaded block 99/192
[2026-03-22 21:08:05,543][utils.updater][DEBUG] Successfully uploaded block 100/192
[2026-03-22 21:08:05,543][utils.updater][DEBUG] Received data packet op=3, block=100, len=1284
[2026-03-22 21:08:05,648][utils.updater][DEBUG] Successfully uploaded block 100/192
[2026-03-22 21:08:05,648][utils.updater][DEBUG] Successfully uploaded block 101/192
[2026-03-22 21:08:05,648][utils.updater][DEBUG] Received data packet op=3, block=101, len=1284
[2026-03-22 21:08:05,753][utils.updater][DEBUG] Successfully uploaded block 101/192
[2026-03-22 21:08:05,753][utils.updater][DEBUG] Successfully uploaded block 102/192
[2026-03-22 21:08:05,753][utils.updater][DEBUG] Received data packet op=3, block=102, len=1284
[2026-03-22 21:08:05,858][utils.updater][DEBUG] Successfully uploaded block 102/192
[2026-03-22 21:08:05,858][utils.updater][DEBUG] Successfully uploaded block 103/192
[2026-03-22 21:08:05,858][utils.updater][DEBUG] Received data packet op=3, block=103, len=1284
[2026-03-22 21:08:05,963][utils.updater][DEBUG] Successfully uploaded block 103/192
[2026-03-22 21:08:05,963][utils.updater][DEBUG] Successfully uploaded block 104/192
[2026-03-22 21:08:05,963][utils.updater][DEBUG] Received data packet op=3, block=104, len=1284
[2026-03-22 21:08:06,068][utils.updater][DEBUG] Successfully uploaded block 104/192
[2026-03-22 21:08:06,068][utils.updater][DEBUG] Successfully uploaded block 105/192
[2026-03-22 21:08:06,068][utils.updater][DEBUG] Received data packet op=3, block=105, len=1284
[2026-03-22 21:08:06,173][utils.updater][DEBUG] Successfully uploaded block 105/192
[2026-03-22 21:08:06,173][utils.updater][DEBUG] Successfully uploaded block 106/192
[2026-03-22 21:08:06,173][utils.updater][DEBUG] Received data packet op=3, block=106, len=1284
[2026-03-22 21:08:06,278][utils.updater][DEBUG] Successfully uploaded block 106/192
[2026-03-22 21:08:06,278][utils.updater][DEBUG] Successfully uploaded block 107/192
[2026-03-22 21:08:06,278][utils.updater][DEBUG] Received data packet op=3, block=107, len=1284
[2026-03-22 21:08:06,383][utils.updater][DEBUG] Successfully uploaded block 107/192
[2026-03-22 21:08:06,383][utils.updater][DEBUG] Successfully uploaded block 108/192
[2026-03-22 21:08:06,383][utils.updater][DEBUG] Received data packet op=3, block=108, len=1284
[2026-03-22 21:08:06,488][utils.updater][DEBUG] Successfully uploaded block 108/192
[2026-03-22 21:08:06,488][utils.updater][DEBUG] Successfully uploaded block 109/192
[2026-03-22 21:08:06,488][utils.updater][DEBUG] Received data packet op=3, block=109, len=1284
[2026-03-22 21:08:06,593][utils.updater][DEBUG] Successfully uploaded block 109/192
[2026-03-22 21:08:06,593][utils.updater][DEBUG] Successfully uploaded block 110/192
[2026-03-22 21:08:06,593][utils.updater][DEBUG] Received data packet op=3, block=110, len=1284
[2026-03-22 21:08:06,698][utils.updater][DEBUG] Successfully uploaded block 110/192
[2026-03-22 21:08:06,698][utils.updater][DEBUG] Successfully uploaded block 111/192
[2026-03-22 21:08:06,698][utils.updater][DEBUG] Received data packet op=3, block=111, len=1284
[2026-03-22 21:08:06,803][utils.updater][DEBUG] Successfully uploaded block 111/192
[2026-03-22 21:08:06,803][utils.updater][DEBUG] Successfully uploaded block 112/192
[2026-03-22 21:08:06,803][utils.updater][DEBUG] Received data packet op=3, block=112, len=1284
[2026-03-22 21:08:06,908][utils.updater][DEBUG] Successfully uploaded block 112/192
[2026-03-22 21:08:06,908][utils.updater][DEBUG] Successfully uploaded block 113/192
[2026-03-22 21:08:06,908][utils.updater][DEBUG] Received data packet op=3, block=113, len=1284
[2026-03-22 21:08:07,013][utils.updater][DEBUG] Successfully uploaded block 113/192
[2026-03-22 21:08:07,013][utils.updater][DEBUG] Successfully uploaded block 114/192
[2026-03-22 21:08:07,013][utils.updater][DEBUG] Received data packet op=3, block=114, len=1284
[2026-03-22 21:08:07,118][utils.updater][DEBUG] Successfully uploaded block 114/192
[2026-03-22 21:08:07,118][utils.updater][DEBUG] Successfully uploaded block 115/192
[2026-03-22 21:08:07,118][utils.updater][DEBUG] Received data packet op=3, block=115, len=1284
[2026-03-22 21:08:07,223][utils.updater][DEBUG] Successfully uploaded block 115/192
[2026-03-22 21:08:07,223][utils.updater][DEBUG] Successfully uploaded block 116/192
[2026-03-22 21:08:07,223][utils.updater][DEBUG] Received data packet op=3, block=116, len=1284
[2026-03-22 21:08:07,328][utils.updater][DEBUG] Successfully uploaded block 116/192
[2026-03-22 21:08:07,328][utils.updater][DEBUG] Successfully uploaded block 117/192
[2026-03-22 21:08:07,328][utils.updater][DEBUG] Received data packet op=3, block=117, len=1284
[2026-03-22 21:08:07,433][utils.updater][DEBUG] Successfully uploaded block 117/192
[2026-03-22 21:08:07,433][utils.updater][DEBUG] Successfully uploaded block 118/192
[2026-03-22 21:08:07,433][utils.updater][DEBUG] Received data packet op=3, block=118, len=1284
[2026-03-22 21:08:07,538][utils.updater][DEBUG] Successfully uploaded block 118/192
[2026-03-22 21:08:07,538][utils.updater][DEBUG] Successfully uploaded block 119/192
[2026-03-22 21:08:07,538][utils.updater][DEBUG] Received data packet op=3, block=119, len=1284
[2026-03-22 21:08:07,643][utils.updater][DEBUG] Successfully uploaded block 119/192
[2026-03-22 21:08:07,643][utils.updater][DEBUG] Successfully uploaded block 120/192
[2026-03-22 21:08:07,643][utils.updater][DEBUG] Received data packet op=3, block=120, len=1284
[2026-03-22 21:08:07,748][utils.updater][DEBUG] Successfully uploaded block 120/192
[2026-03-22 21:08:07,748][utils.updater][DEBUG] Successfully uploaded block 121/192
[2026-03-22 21:08:07,748][utils.updater][DEBUG] Received data packet op=3, block=121, len=1284
[2026-03-22 21:08:07,853][utils.updater][DEBUG] Successfully uploaded block 121/192
[2026-03-22 21:08:07,853][utils.updater][DEBUG] Successfully uploaded block 122/192
[2026-03-22 21:08:07,853][utils.updater][DEBUG] Received data packet op=3, block=122, len=1284
[2026-03-22 21:08:07,958][utils.updater][DEBUG] Successfully uploaded block 122/192
[2026-03-22 21:08:07,958][utils.updater][DEBUG] Successfully uploaded block 123/192
[2026-03-22 21:08:07,958][utils.updater][DEBUG] Received data packet op=3, block=123, len=1284
[2026-03-22 21:08:08,063][utils.updater][DEBUG] Successfully uploaded block 123/192
[2026-03-22 21:08:08,063][utils.updater][DEBUG] Successfully uploaded block 124/192
[2026-03-22 21:08:08,063][utils.updater][DEBUG] Received data packet op=3, block=124, len=1284
[2026-03-22 21:08:08,168][utils.updater][DEBUG] Successfully uploaded block 124/192
[2026-03-22 21:08:08,168][utils.updater][DEBUG] Successfully uploaded block 125/192
[2026-03-22 21:08:08,168][utils.updater][DEBUG] Received data packet op=3, block=125, len=1284
[2026-03-22 21:08:08,273][utils.updater][DEBUG] Successfully uploaded block 125/192
[2026-03-22 21:08:08,273][utils.updater][DEBUG] Successfully uploaded block 126/192
[2026-03-22 21:08:08,273][utils.updater][DEBUG] Received data packet op=3, block=126, len=1284
[2026-03-22 21:08:08,378][utils.updater][DEBUG] Successfully uploaded block 126/192
[2026-03-22 21:08:08,378][utils.updater][DEBUG] Successfully uploaded block 127/192
[2026-03-22 21:08:08,378][utils.updater][DEBUG] Received data packet op=3, block=127, len=1284
[2026-03-22 21:08:08,483][utils.updater][DEBUG] Successfully uploaded block 127/192
[2026-03-22 21:08:08,483][utils.updater][DEBUG] Successfully uploaded block 128/192
[2026-03-22 21:08:08,483][utils.updater][DEBUG] Received data packet op=3, block=128, len=1284
[2026-03-22 21:08:08,588][utils.updater][DEBUG] Successfully uploaded block 128/192
[2026-03-22 21:08:08,588][utils.updater][DEBUG] Successfully uploaded block 129/192
[2026-03-22 21:08:08,588][utils.updater][DEBUG] Received data packet op=3, block=129, len=1284
[2026-03-22 21:08:08,693][utils.updater][DEBUG] Successfully uploaded block 129/192
[2026-03-22 21:08:08,693][utils.updater][DEBUG] Successfully uploaded block 130/192
[2026-03-22 21:08:08,693][utils.updater][DEBUG] Received data packet op=3, block=130, len=1284
[2026-03-22 21:08:08,798][utils.updater][DEBUG] Successfully uploaded block 130/192
[2026-03-22 21:08:08,798][utils.updater][DEBUG] Successfully uploaded block 131/192
[2026-03-22 21:08:08,798][utils.updater][DEBUG] Received data packet op=3, block=131, len=1284
[2026-03-22 21:08:08,903][utils.updater][DEBUG] Successfully uploaded block 131/192
[2026-03-22 21:08:08,903][utils.updater][DEBUG] Successfully uploaded block 132/192
[2026-03-22 21:08:08,903][utils.updater][DEBUG] Received data packet op=3, block=132, len=1284
[2026-03-22 21:08:09,008][utils.updater][DEBUG] Successfully uploaded block 132/192
[2026-03-22 21:08:09,008][utils.updater][DEBUG] Successfully uploaded block 133/192
[2026-03-22 21:08:09,008][utils.updater][DEBUG] Received data packet op=3, block=133, len=1284
[2026-03-22 21:08:09,113][utils.updater][DEBUG] Successfully uploaded block 133/192
[2026-03-22 21:08:09,113][utils.updater][DEBUG] Successfully uploaded block 134/192
[2026-03-22 21:08:09,113][utils.updater][DEBUG] Received data packet op=3, block=134, len=1284
[2026-03-22 21:08:09,218][utils.updater][DEBUG] Successfully uploaded block 134/192
[2026-03-22 21:08:09,218][utils.updater][DEBUG] Successfully uploaded block 135/192
[2026-03-22 21:08:09,218][utils.updater][DEBUG] Received data packet op=3, block=135, len=1284
[2026-03-22 21:08:09,323][utils.updater][DEBUG] Successfully uploaded block 135/192
[2026-03-22 21:08:09,323][utils.updater][DEBUG] Successfully uploaded block 136/192
[2026-03-22 21:08:09,323][utils.updater][DEBUG] Received data packet op=3, block=136, len=1284
[2026-03-22 21:08:09,428][utils.updater][DEBUG] Successfully uploaded block 136/192
[2026-03-22 21:08:09,428][utils.updater][DEBUG] Successfully uploaded block 137/192
[2026-03-22 21:08:09,428][utils.updater][DEBUG] Received data packet op=3, block=137, len=1284
[2026-03-22 21:08:09,533][utils.updater][DEBUG] Successfully uploaded block 137/192
[2026-03-22 21:08:09,533][utils.updater][DEBUG] Successfully uploaded block 138/192
[2026-03-22 21:08:09,533][utils.updater][DEBUG] Received data packet op=3, block=138, len=1284
[2026-03-22 21:08:09,638][utils.updater][DEBUG] Successfully uploaded block 138/192
[2026-03-22 21:08:09,638][utils.updater][DEBUG] Successfully uploaded block 139/192
[2026-03-22 21:08:09,638][utils.updater][DEBUG] Received data packet op=3, block=139, len=1284
[2026-03-22 21:08:09,743][utils.updater][DEBUG] Successfully uploaded block 139/192
[2026-03-22 21:08:09,743][utils.updater][DEBUG] Successfully uploaded block 140/192
[2026-03-22 21:08:09,743][utils.updater][DEBUG] Received data packet op=3, block=140, len=1284
[2026-03-22 21:08:09,848][utils.updater][DEBUG] Successfully uploaded block 140/192
[2026-03-22 21:08:09,848][utils.updater][DEBUG] Successfully uploaded block 141/192
[2026-03-22 21:08:09,848][utils.updater][DEBUG] Received data packet op=3, block=141, len=1284
[2026-03-22 21:08:09,953][utils.updater][DEBUG] Successfully uploaded block 141/192
[2026-03-22 21:08:09,953][utils.updater][DEBUG] Successfully uploaded block 142/192
[2026-03-22 21:08:09,953][utils.updater][DEBUG] Received data packet op=3, block=142, len=1284
[2026-03-22 21:08:10,058][utils.updater][DEBUG] Successfully uploaded block 142/192
[2026-03-22 21:08:10,058][utils.updater][DEBUG] Successfully uploaded block 143/192
[2026-03-22 21:08:10,058][utils.updater][DEBUG] Received data packet op=3, block=143, len=1284
[2026-03-22 21:08:10,163][utils.updater][DEBUG] Successfully uploaded block 143/192
[2026-03-22 21:08:10,163][utils.updater][DEBUG] Successfully uploaded block 144/192
[2026-03-22 21:08:10,163][utils.updater][DEBUG] Received data packet op=3, block=144, len=1284
[2026-03-22 21:08:10,268][utils.updater][DEBUG] Successfully uploaded block 144/192
[2026-03-22 21:08:10,268][utils.updater][DEBUG] Successfully uploaded block 145/192
[2026-03-22 21:08:10,268][utils.updater][DEBUG] Received data packet op=3, block=145, len=1284
[2026-03-22 21:08:10,373][utils.updater][DEBUG] Successfully uploaded block 145/192
[2026-03-22 21:08:10,373][utils.updater][DEBUG] Successfully uploaded block 146/192
[2026-03-22 21:08:10,373][utils.updater][DEBUG] Received data packet op=3, block=146, len=1284
[2026-03-22 21:08:10,478][utils.updater][DEBUG] Successfully uploaded block 146/192
[2026-03-22 21:08:10,478][utils.updater][DEBUG] Successfully uploaded block 147/192
[2026-03-22 21:08:10,478][utils.updater][DEBUG] Received data packet op=3, block=147, len=1284
[2026-03-22 21:08:10,583][utils.updater][DEBUG] Successfully uploaded block 147/192
[2026-03-22 21:08:10,583][utils.updater][DEBUG] Successfully uploaded block 148/192
[2026-03-22 21:08:10,583][utils.updater][DEBUG] Received data packet op=3, block=148, len=1284
[2026-03-22 21:08:10,688][utils.updater][DEBUG] Successfully uploaded block 148/192
[2026-03-22 21:08:10,688][utils.updater][DEBUG] Successfully uploaded block 149/192
[2026-03-22 21:08:10,688][utils.updater][DEBUG] Received data packet op=3, block=149, len=1284
[2026-03-22 21:08:10,793][utils.updater][DEBUG] Successfully uploaded block 149/192
[2026-03-22 21:08:10,793][utils.updater][DEBUG] Successfully uploaded block 150/192
[2026-03-22 21:08:10,793][utils.updater][DEBUG] Received data packet op=3, block=150, len=1284
[2026-03-22 21:08:10,898][utils.updater][DEBUG] Successfully uploaded block 150/192
[2026-03-22 21:08:10,898][utils.updater][DEBUG] Successfully uploaded block 151/192
[2026-03-22 21:08:10,898][utils.updater][DEBUG] Received data packet op=3, block=151, len=1284
[2026-03-22 21:08:11,003][utils.updater][DEBUG] Successfully uploaded block 151/192
[2026-03-22 21:08:11,003][utils.updater][DEBUG] Successfully uploaded block 152/192
[2026-03-22 21:08:11,003][utils.updater][DEBUG] Received data packet op=3, block=152, len=1284
[2026-03-22 21:08:11,108][utils.updater][DEBUG] Successfully uploaded block 152/192
[2026-03-22 21:08:11,108][utils.updater][DEBUG] Successfully uploaded block 153/192
[2026-03-22 21:08:11,108][utils.updater][DEBUG] Received data packet op=3, block=153, len=1284
[2026-03-22 21:08:11,213][utils.updater][DEBUG] Successfully uploaded block 153/192
[2026-03-22 21:08:11,213][utils.updater][DEBUG] Successfully uploaded block 154/192
[2026-03-22 21:08:11,213][utils.updater][DEBUG] Received data packet op=3, block=154, len=1284
[2026-03-22 21:08:11,318][utils.updater][DEBUG] Successfully uploaded block 154/192
[2026-03-22 21:08:11,318][utils.updater][DEBUG] Successfully uploaded block 155/192
[2026-03-22 21:08:11,318][utils.updater][DEBUG] Received data packet op=3, block=155, len=1284
[2026-03-22 21:08:11,423][utils.updater][DEBUG] Successfully uploaded block 155/192
[2026-03-22 21:08:11,423][utils.updater][DEBUG] Successfully uploaded block 156/192
[2026-03-22 21:08:11,423][utils.updater][DEBUG] Received data packet op=3, block=156, len=1284
[2026-03-22 21:08:11,528][utils.updater][DEBUG] Successfully uploaded block 156/192
[2026-03-22 21:08:11,528][utils.updater][DEBUG] Successfully uploaded block 157/192
[2026-03-22 21:08:11,528][utils.updater][DEBUG] Received data packet op=3, block=157, len=1284
[2026-03-22 21:08:11,636][utils.updater][DEBUG] Successfully uploaded block 157/192
[2026-03-22 21:08:11,636][utils.updater][DEBUG] Successfully uploaded block 158/192
[2026-03-22 21:08:11,636][utils.updater][DEBUG] Received data packet op=3, block=158, len=1284
[2026-03-22 21:08:11,741][utils.updater][DEBUG] Successfully uploaded block 158/192
[2026-03-22 21:08:11,741][utils.updater][DEBUG] Successfully uploaded block 159/192
[2026-03-22 21:08:11,741][utils.updater][DEBUG] Received data packet op=3, block=159, len=1284
[2026-03-22 21:08:11,846][utils.updater][DEBUG] Successfully uploaded block 159/192
[2026-03-22 21:08:11,846][utils.updater][DEBUG] Successfully uploaded block 160/192
[2026-03-22 21:08:11,846][utils.updater][DEBUG] Received data packet op=3, block=160, len=1284
[2026-03-22 21:08:11,951][utils.updater][DEBUG] Successfully uploaded block 160/192
[2026-03-22 21:08:11,951][utils.updater][DEBUG] Successfully uploaded block 161/192
[2026-03-22 21:08:11,951][utils.updater][DEBUG] Received data packet op=3, block=161, len=1284
[2026-03-22 21:08:12,056][utils.updater][DEBUG] Successfully uploaded block 161/192
[2026-03-22 21:08:12,056][utils.updater][DEBUG] Successfully uploaded block 162/192
[2026-03-22 21:08:12,056][utils.updater][DEBUG] Received data packet op=3, block=162, len=1284
[2026-03-22 21:08:12,161][utils.updater][DEBUG] Successfully uploaded block 162/192
[2026-03-22 21:08:12,161][utils.updater][DEBUG] Successfully uploaded block 163/192
[2026-03-22 21:08:12,161][utils.updater][DEBUG] Received data packet op=3, block=163, len=1284
[2026-03-22 21:08:12,266][utils.updater][DEBUG] Successfully uploaded block 163/192
[2026-03-22 21:08:12,266][utils.updater][DEBUG] Successfully uploaded block 164/192
[2026-03-22 21:08:12,266][utils.updater][DEBUG] Received data packet op=3, block=164, len=1284
[2026-03-22 21:08:12,371][utils.updater][DEBUG] Successfully uploaded block 164/192
[2026-03-22 21:08:12,371][utils.updater][DEBUG] Successfully uploaded block 165/192
[2026-03-22 21:08:12,371][utils.updater][DEBUG] Received data packet op=3, block=165, len=1284
[2026-03-22 21:08:12,476][utils.updater][DEBUG] Successfully uploaded block 165/192
[2026-03-22 21:08:12,476][utils.updater][DEBUG] Successfully uploaded block 166/192
[2026-03-22 21:08:12,476][utils.updater][DEBUG] Received data packet op=3, block=166, len=1284
[2026-03-22 21:08:12,581][utils.updater][DEBUG] Successfully uploaded block 166/192
[2026-03-22 21:08:12,581][utils.updater][DEBUG] Successfully uploaded block 167/192
[2026-03-22 21:08:12,581][utils.updater][DEBUG] Received data packet op=3, block=167, len=1284
[2026-03-22 21:08:12,686][utils.updater][DEBUG] Successfully uploaded block 167/192
[2026-03-22 21:08:12,686][utils.updater][DEBUG] Successfully uploaded block 168/192
[2026-03-22 21:08:12,686][utils.updater][DEBUG] Received data packet op=3, block=168, len=1284
[2026-03-22 21:08:12,791][utils.updater][DEBUG] Successfully uploaded block 168/192
[2026-03-22 21:08:12,791][utils.updater][DEBUG] Successfully uploaded block 169/192
[2026-03-22 21:08:12,791][utils.updater][DEBUG] Received data packet op=3, block=169, len=1284
[2026-03-22 21:08:12,896][utils.updater][DEBUG] Successfully uploaded block 169/192
[2026-03-22 21:08:12,896][utils.updater][DEBUG] Successfully uploaded block 170/192
[2026-03-22 21:08:12,896][utils.updater][DEBUG] Received data packet op=3, block=170, len=1284
[2026-03-22 21:08:13,001][utils.updater][DEBUG] Successfully uploaded block 170/192
[2026-03-22 21:08:13,001][utils.updater][DEBUG] Successfully uploaded block 171/192
[2026-03-22 21:08:13,001][utils.updater][DEBUG] Received data packet op=3, block=171, len=1284
[2026-03-22 21:08:13,106][utils.updater][DEBUG] Successfully uploaded block 171/192
[2026-03-22 21:08:13,106][utils.updater][DEBUG] Successfully uploaded block 172/192
[2026-03-22 21:08:13,106][utils.updater][DEBUG] Received data packet op=3, block=172, len=1284
[2026-03-22 21:08:13,211][utils.updater][DEBUG] Successfully uploaded block 172/192
[2026-03-22 21:08:13,211][utils.updater][DEBUG] Successfully uploaded block 173/192
[2026-03-22 21:08:13,211][utils.updater][DEBUG] Received data packet op=3, block=173, len=1284
[2026-03-22 21:08:13,316][utils.updater][DEBUG] Successfully uploaded block 173/192
[2026-03-22 21:08:13,316][utils.updater][DEBUG] Successfully uploaded block 174/192
[2026-03-22 21:08:13,316][utils.updater][DEBUG] Received data packet op=3, block=174, len=1284
[2026-03-22 21:08:13,421][utils.updater][DEBUG] Successfully uploaded block 174/192
[2026-03-22 21:08:13,421][utils.updater][DEBUG] Successfully uploaded block 175/192
[2026-03-22 21:08:13,421][utils.updater][DEBUG] Received data packet op=3, block=175, len=1284
[2026-03-22 21:08:13,526][utils.updater][DEBUG] Successfully uploaded block 175/192
[2026-03-22 21:08:13,526][utils.updater][DEBUG] Successfully uploaded block 176/192
[2026-03-22 21:08:13,527][utils.updater][DEBUG] Received data packet op=3, block=176, len=1284
[2026-03-22 21:08:13,633][utils.updater][DEBUG] Successfully uploaded block 176/192
[2026-03-22 21:08:13,633][utils.updater][DEBUG] Successfully uploaded block 177/192
[2026-03-22 21:08:13,633][utils.updater][DEBUG] Received data packet op=3, block=177, len=1284
[2026-03-22 21:08:13,738][utils.updater][DEBUG] Successfully uploaded block 177/192
[2026-03-22 21:08:13,738][utils.updater][DEBUG] Successfully uploaded block 178/192
[2026-03-22 21:08:13,738][utils.updater][DEBUG] Received data packet op=3, block=178, len=1284
[2026-03-22 21:08:13,843][utils.updater][DEBUG] Successfully uploaded block 178/192
[2026-03-22 21:08:13,843][utils.updater][DEBUG] Successfully uploaded block 179/192
[2026-03-22 21:08:13,843][utils.updater][DEBUG] Received data packet op=3, block=179, len=1284
[2026-03-22 21:08:13,948][utils.updater][DEBUG] Successfully uploaded block 179/192
[2026-03-22 21:08:13,948][utils.updater][DEBUG] Successfully uploaded block 180/192
[2026-03-22 21:08:13,948][utils.updater][DEBUG] Received data packet op=3, block=180, len=1284
[2026-03-22 21:08:14,053][utils.updater][DEBUG] Successfully uploaded block 180/192
[2026-03-22 21:08:14,053][utils.updater][DEBUG] Successfully uploaded block 181/192
[2026-03-22 21:08:14,053][utils.updater][DEBUG] Received data packet op=3, block=181, len=1284
[2026-03-22 21:08:14,158][utils.updater][DEBUG] Successfully uploaded block 181/192
[2026-03-22 21:08:14,158][utils.updater][DEBUG] Successfully uploaded block 182/192
[2026-03-22 21:08:14,158][utils.updater][DEBUG] Received data packet op=3, block=182, len=1284
[2026-03-22 21:08:14,263][utils.updater][DEBUG] Successfully uploaded block 182/192
[2026-03-22 21:08:14,263][utils.updater][DEBUG] Successfully uploaded block 183/192
[2026-03-22 21:08:14,263][utils.updater][DEBUG] Received data packet op=3, block=183, len=1284
[2026-03-22 21:08:14,368][utils.updater][DEBUG] Successfully uploaded block 183/192
[2026-03-22 21:08:14,368][utils.updater][DEBUG] Successfully uploaded block 184/192
[2026-03-22 21:08:14,368][utils.updater][DEBUG] Received data packet op=3, block=184, len=1284
[2026-03-22 21:08:14,473][utils.updater][DEBUG] Successfully uploaded block 184/192
[2026-03-22 21:08:14,473][utils.updater][DEBUG] Successfully uploaded block 185/192
[2026-03-22 21:08:14,473][utils.updater][DEBUG] Received data packet op=3, block=185, len=1284
[2026-03-22 21:08:14,578][utils.updater][DEBUG] Successfully uploaded block 185/192
[2026-03-22 21:08:14,578][utils.updater][DEBUG] Successfully uploaded block 186/192
[2026-03-22 21:08:14,578][utils.updater][DEBUG] Received data packet op=3, block=186, len=1284
[2026-03-22 21:08:14,683][utils.updater][DEBUG] Successfully uploaded block 186/192
[2026-03-22 21:08:14,683][utils.updater][DEBUG] Successfully uploaded block 187/192
[2026-03-22 21:08:14,683][utils.updater][DEBUG] Received data packet op=3, block=187, len=1284
[2026-03-22 21:08:14,788][utils.updater][DEBUG] Successfully uploaded block 187/192
[2026-03-22 21:08:14,788][utils.updater][DEBUG] Successfully uploaded block 188/192
[2026-03-22 21:08:14,788][utils.updater][DEBUG] Received data packet op=3, block=188, len=1284
[2026-03-22 21:08:14,893][utils.updater][DEBUG] Successfully uploaded block 188/192
[2026-03-22 21:08:14,893][utils.updater][DEBUG] Successfully uploaded block 189/192
[2026-03-22 21:08:14,893][utils.updater][DEBUG] Received data packet op=3, block=189, len=1284
[2026-03-22 21:08:14,998][utils.updater][DEBUG] Successfully uploaded block 189/192
[2026-03-22 21:08:14,998][utils.updater][DEBUG] Successfully uploaded block 190/192
[2026-03-22 21:08:14,998][utils.updater][DEBUG] Received data packet op=3, block=190, len=1284
[2026-03-22 21:08:15,103][utils.updater][DEBUG] Successfully uploaded block 190/192
[2026-03-22 21:08:15,103][utils.updater][DEBUG] Successfully uploaded block 191/192
[2026-03-22 21:08:15,103][utils.updater][DEBUG] Received data packet op=3, block=191, len=1284
[2026-03-22 21:08:15,208][utils.updater][DEBUG] Successfully uploaded block 191/192
[2026-03-22 21:08:15,208][tftpy.TftpStates][DEBUG] Reached EOF on file BearDriver.txt
[2026-03-22 21:08:15,208][utils.updater][DEBUG] Successfully uploaded block 192/192
[2026-03-22 21:08:15,208][utils.updater][DEBUG] Received data packet op=3, block=192, len=1210
[2026-03-22 21:08:15,313][utils.updater][DEBUG] Successfully uploaded block 192/192
[2026-03-22 21:08:15,313][tftpy.TftpStates][DEBUG] Received ACK to final DAT, we're done.
[2026-03-22 21:08:15,313][tftpy.TftpClient][DEBUG]
[2026-03-22 21:08:15,313][utils.updater][DEBUG] Total bytes Received: 245686 bytes
[2026-03-22 21:08:15,313][tftpy.TftpClient][DEBUG] Upload complete.
[2026-03-22 21:08:15,313][tftpy.TftpClient][DEBUG] Uploaded 245686 bytes in 20.27 seconds
[2026-03-22 21:08:15,314][tftpy.TftpClient][DEBUG] Average rate: 94.67 kbps
[2026-03-22 21:08:15,314][tftpy.TftpClient][DEBUG] 0.00 bytes in resent data
[2026-03-22 21:08:15,314][utils.updater][DEBUG] State: Download Finished
[2026-03-22 21:08:15,314][tftpy.TftpClient][DEBUG] Resent 0 packets
[2026-03-22 21:08:15,314][utils.updater][DEBUG] Upload Complete
[2026-03-22 21:08:15,978][utils.updater][INFO] BLDC flash in progress. This may take up to 90 seconds.
[2026-03-22 21:09:12,746][utils.updater][DEBUG] BLDC flashed from SPI flash OK.
[2026-03-22 21:09:13,245][utils.updater][DEBUG] OTA Update OK
[2026-03-22 21:09:13,647][utils.updater][DEBUG] BLDC flashed.
[2026-03-22 21:09:13,647][utils.updater][DEBUG] System will reset in 5 sec.
[2026-03-22 21:09:13,648][root][INFO] Image upload was successful
[2026-03-22 21:09:13,648][root][INFO] Waiting 10 seconds before sending ping...
[2026-03-22 21:09:23,658][root][INFO] Waiting up to 60.0 seconds for Baseboard connectivity...
[2026-03-22 21:09:35,691][root][INFO] Restart and flash complete. Waiting 10 sec for baseboard to initialize.
[2026-03-22 21:09:45,702][root][INFO] Initialization complete.
[2026-03-22 21:09:45,702][root][INFO] Waiting 20 seconds for motor board to initialize
[2026-03-22 21:10:05,722][root][DEBUG] Sent command 9 to baseboard
[2026-03-22 21:10:07,723][root][DEBUG] Sent command 11 to baseboard
[2026-03-22 21:10:07,723][root][INFO] Current Motor Pcb Version : 15
[2026-03-22 21:10:07,723][root][INFO] OTA is finished successfully.
$
```

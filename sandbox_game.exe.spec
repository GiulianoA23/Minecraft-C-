# sandbox_game.spec
# ...
exe = EXE(
    pyz,
    a.scripts,
    a.binaries,
    a.zipfiles,
    a.datas,
    [],
    name='sandbox_game',
    debug=False,
    bootloader_ignore_signals=False,
    strip=False,
    upx=True,
    console=True,
    manifest='''<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
    <assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
        <compatibility xmlns="urn:schemas-microsoft-com:compatibility.v1">
            <application>
                <!-- Windows Vista -->
                <supportedOS Id="{e2011457-1546-43c5-a5fe-008deee3d3f0}"/>
                <!-- Windows 7 -->
                <supportedOS Id="{35138b9a-5d96-4fbd-8e2d-a2440225f93a}"/>
                <!-- Windows 8 -->
                <supportedOS Id="{4d402a4a-8500-45b6-a5aa-bf6f4f2a6c00}"/>
                <!-- Windows 8.1 -->
                <supportedOS Id="{1E418766-7E91-4a95-B241-4F7E71864556}"/>
                <!-- Windows 10 -->
                <supportedOS Id="{8e0f7a12-bfb3-4fe8-b9a5-48fd50a15a9a}"/>
            </application>
        </compatibility>
    </assembly>''',
    icon=None
)

# version-injector

This is super lightweight DLL which will proxy any version.dll calls to system32's version.dll with the addition of running code.
This DLL should be placed in the directory of your application you'd like to target keeping its name untouched, this is known as an IMPORT hijacking attack.

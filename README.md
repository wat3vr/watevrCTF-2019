![logo](logo.png)

# watevrCTF 2019

[![Build Status](https://travis-ci.com/mateuszdrwal/watevrCTF-2019.svg?token=4HxouMSxJNRpTrgxhYqN&branch=master)](https://travis-ci.com/mateuszdrwal/watevrCTF-2019)

repository for the first watevrCTF

## For visitors:

Welcome!

This is the repository where you will find all challenges from watevrCTF 2019. All challenges have their sources and build scripts here, so you can explore how they were made. Most of the challenges also have automated solve scripts that you can investigate for a solution, and a few even have writeups.

If you want to start a web or pwn challenge locally here is how you do it:

The file `install_dependencies.sh` installs almost all dependencies required for building, running and solving challenges. If you are lazy you can just run that script to get set up, but please look at it and make sure you are ok with how it is installing stuff first. The only thing it doesn't install is docker-ce, which is required for starting all service based challenges. You will also have to install that yourself.

All these scripts were designed to be ran on linux, so we can't guarantee anything for windows, but you could always try running them in WSL 2.

To build challenge docker images, you have to run `sudo python3 challtools.py build <challenge title>` from the repository root. Then to start the container you run `sudo python3 challtools.py start <challenge title>`. For example, if you want to start the "Super Calculator" challenge for the first time you would run:

```
$ sudo python3 challtools.py build super calculator
challenge: Super Calculator
flag: watevr{d0_y0u_l1k3_my_c55_5h4d0w5}
building challenge...
    running build script...
    building docker image...
build done!
$ sudo python3 challtools.py start super calculator
challenge: Super Calculator
starting challenge...
services hosted at:
http://127.0.0.1:50000
[2019-12-15 15:47:17 +0000] [11] [INFO] Starting gunicorn 20.0.4
[2019-12-15 15:47:17 +0000] [11] [INFO] Listening at: http://0.0.0.0:8000 (11)
[2019-12-15 15:47:17 +0000] [11] [INFO] Using worker: sync
[2019-12-15 15:47:17 +0000] [28] [INFO] Booting worker with pid: 28
[2019-12-15 15:47:17 +0000] [29] [INFO] Booting worker with pid: 29
[2019-12-15 15:47:17 +0000] [32] [INFO] Booting worker with pid: 32
[2019-12-15 15:47:17 +0000] [33] [INFO] Booting worker with pid: 33
[2019-12-15 15:47:17 +0000] [35] [INFO] Booting worker with pid: 35
[2019-12-15 15:47:17 +0000] [37] [INFO] Booting worker with pid: 37
```

Then you will be able to access super calculator at <http://127.0.0.1:50000>. You need to use the links right after `services hosted at:`, after those the logs from inside the docker container are shown, therefore, <http://0.0.0.0:8000> won't work since that's only reachable from inside the docker container.

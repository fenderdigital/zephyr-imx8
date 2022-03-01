.. _imx8mn_evk:

NXP i.MX8MN EVK (Cortex-A53)
############################

Overview
********

i.MX8M Nano LPDDR4 EVK board is based on NXP i.MX8M Nano applications
processor, composed of a quad Cortex®-A53 cluster and a single Cortex®-M7 core.
Zephyr OS is ported to run on the Cortex®-A53 core.

- Board features:

  - RAM: 2GB LPDDR4
  - Storage:

    - SanDisk 16GB eMMC5.1
    - Micron 32MB QSPI NOR
    - microSD Socket
  - Wireless: NXP 88W8987 module

    - WiFi 5 (1x1)
    - Bluetooth 5
  - USB:

    - OTG - 2x type C
  - Ethernet
  - PCI-E M.2
  - Connectors:

    - 40-Pin Dual Row Header
  - LEDs:

    - 1x Power status LED
    - 1x UART LED
  - Debug

    - JTAG 20-pin connector
    - MicroUSB for UART debug, two COM ports for A53 and M7

More information about the board can be found at the
`NXP website`_.

Supported Features
==================

The Zephyr imx8mn_evk board configuration supports the following hardware
features:

+-----------+------------+-------------------------------------+
| Interface | Controller | Driver/Component                    |
+===========+============+=====================================+
| GIC-v3    | on-chip    | interrupt controller                |
+-----------+------------+-------------------------------------+
| ARM TIMER | on-chip    | system clock                        |
+-----------+------------+-------------------------------------+
| UART      | on-chip    | serial port                         |
+-----------+------------+-------------------------------------+

Devices
========
System Clock
------------

Quad Cortex-A53 processors operation up to 1.5 GHz.

Serial Port
-----------

EVK board has two independent UART Ports (UART1, UART2),  UART2 is used for Zephyr serial console.

Programming and Debugging
*************************

1. Build Zephyr Applications

Use this configuration to build basic Zephyr applications and kernel tests,
for example, with the :ref:`hello_world` for non-SMP mode:

.. zephyr-app-commands::
   :zephyr-app: samples/hello_world
   :host-os: unix
   :board: mimx8mn_evk_a53
   :goals: build

Or build with SMP mode:

.. zephyr-app-commands::
   :zephyr-app: samples/hello_world
   :host-os: unix
   :board: mimx8mn_evk_a53_smp
   :goals: build

This will build an image with the hello_world sample app.


.. code-block:: console

       *** Booting Zephyr OS build v3.0.0-rc3-13-ga8fc78cc0d59  ***
       Hello World! mimx8mn_evk_a53

2. Running Zephyr on Jailhouse Inmate Cell

Use the following command to run Zephyr in Jailhouse inmate, need to configure Jailhouse
inmate Cell to use a single Core for Zephyr non-SMP mode, or use Core2 and Core3
for Zephyr SMP 2cores image.

1) Use root Cell dts to boot root Cell Linux.

2) Install Jailhouse module:

.. code-block:: console

	modprobe jailhouse

3) Run Zephyr demo in inmate Cell:

.. code-block:: console

	jailhouse enable imx8mn.cell
	jailhouse cell create imx8mn-zephyr.cell
	jailhouse cell load zephyr-inmate-demo zephyr.bin --address 0x93c00000
	jailhouse cell start zephyr-inmate-demo

It will display the following console output on uart4:

.. code-block:: console

	*** Booting Zephyr OS build v3.0.0-rc3-8-g1a0886ed442f  ***
	Hello World! mimx8mn_evk_a53

References
==========

.. _NXP website:
   https://www.nxp.com/document/guide/getting-started-with-the-i-mx-8m-nano-evk-board:GS-8MNANOLPD4-EVK

.. _i.MX 8M Applications Processor Reference Manual:
   https://www.nxp.com/webapp/Download?colCode=IMX8MNRM

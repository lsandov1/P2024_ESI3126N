1. ¿Qué son los dispositivos de bloque y qué son los dispositivos de flujo o caracter?

- bloque: son aquellos que podemos leer por bloques y en cualquier lugar de dicho dispositivo, e.g disco duro

- caracter: los podemos considerar como aquellos que nos proveen un flujo de bytes continuo y no tenemos la capacidad de leer en otro
lugar mas que en ese flujo, e.g. teclado, mouse, impresora

2.  En los aparatos reproductores de música que puedes reproducir audio de una memoria USB
¿Por qué no puedes usar memorias de 32 Gb?

Estos sistemas solo soportan sistemas de archivos tipo MSDOS 'menores' ya sea FAT12 o FAT16. Si estos usaran FAT32, etonces si soportarian volumenes de 32 Gb.

3. Si quisieras usar una memoria mayor a 32 Gb en un reproductor de música que solo "soporta"
memorias de máximo 32 Gb, ¿Hay algo que se pueda hacer?, échate un clavado a Google y busca si hay una solución.

ChatGPT
FAT32 file system has a built-in limitation that restricts the size of a single partition to 32 GB when formatting with most operating systems' built-in tools.
However, there are third-party utilities available that can format larger volumes to FAT32, circumventing this restriction.

One such tool is "fat32format", which is a command-line utility available for Windows. It allows you to format volumes larger than 32 GB to the FAT32 file system.
Another option is using tools like EaseUS Partition Master or MiniTool Partition Wizard, which provide user-friendly interfaces for formatting larger volumes to FAT32.

Keep in mind that while these tools can format larger volumes to FAT32, there are some limitations and considerations to be aware of.
For instance, FAT32 has a file size limit of 4 GB and may not be the best choice for large files or modern storage needs. 
Additionally, FAT32 may not support all features or optimizations of modern file systems like NTFS or exFAT. 
Therefore, it's essential to weigh your requirements and compatibility concerns before formatting a large volume to FAT32.


4. ¿Qué limitaciones tiene FAT32 en cuanto a seguridad?

- No podemos restringir el acceso por usuario o grupo de usuarios, es decir, todos pueden ver todo. NTFS vino a resolver este problema.

5. ¿Recomiendas formatear una memoria USB con NTFS?, explica por qué si o por qué no. Te recomiendo que buscques opiniones en foros que puedes encontrar con Google.   

ChatGPT

Whether it's a good idea to format a USB stick using the NTFS file system depends on your specific needs and the devices you intend to use it with.

Advantages of NTFS:
1. **Support for Large Files**: NTFS supports individual file sizes larger than 4 GB, which can be useful if you need to store large files.
2. **Security Features**: NTFS supports access control lists (ACLs), file permissions, and encryption, which can be beneficial for securing sensitive data.
3. **Journaling**: NTFS includes a journaling feature that helps protect the file system against corruption in case of unexpected power loss or system crashes.

Disadvantages of NTFS:
1. **Compatibility**: While NTFS is widely supported on Windows systems, it may not be fully supported on other operating systems, such as macOS and some Linux distributions. This could limit the usability of the USB stick on those systems.
2. **Performance on Some Devices**: NTFS may not perform optimally on devices with limited processing power or older systems due to its advanced features and overhead.

If you primarily use the USB stick with Windows systems and need to store large files or require advanced security features, formatting it with NTFS could be a good choice. However, if you need cross-platform compatibility or plan to use the USB stick with devices that do not fully support NTFS, you may want to consider alternatives like FAT32 or exFAT.

Ultimately, it's essential to consider your specific requirements and compatibility concerns before deciding on the file system for formatting your USB stick.

6.- ¿Existen sistemas de archivos diseñados específicamente para memorias flash?, pregúntale a Google, y si si existen, ¿cuáles son las ventajas que ofrecen con respecto a otros sistemas de archivos?, es decir, ¿cuál es su razón de existir? 

ChatGPT

Yes, there are specific file systems designed with flash memory devices, like USB flash drives, SSDs, and memory cards, in mind. These file systems aim to optimize performance, endurance, and reliability for flash storage media. Some of the commonly used file systems for flash devices include:

1. **FAT32 (File Allocation Table)**: FAT32 is widely supported across different operating systems and is often used for compatibility reasons, especially for smaller capacity flash drives. However, it has limitations, such as a maximum file size of 4 GB and a maximum volume size of 32 GB.

2. **exFAT (Extended File Allocation Table)**: exFAT is an improved version of FAT32 developed by Microsoft. It supports larger file sizes and volume sizes than FAT32, making it suitable for modern flash drives and memory cards. exFAT is often used when compatibility with various operating systems, including Windows, macOS, and some Linux distributions, is desired.

3. **NTFS (New Technology File System)**: NTFS is a robust file system developed by Microsoft primarily for use with Windows operating systems. While NTFS offers advanced features such as journaling, encryption, and file compression, it may not be the most optimized choice for flash devices due to performance considerations and limited support on non-Windows platforms.

4. **F2FS (Flash-Friendly File System)**: F2FS is a file system specifically designed for NAND flash memory-based storage devices. It is optimized for flash memory characteristics such as wear leveling, garbage collection, and TRIM support. F2FS is commonly used in Linux-based systems, particularly on Android devices and embedded systems.

5. **UBIFS (UBI File System)**: UBIFS is a file system designed for flash memory devices that utilize the Unsorted Block Images (UBI) layer in the Linux kernel. It provides features like wear leveling and power failure tolerance, making it suitable for use in embedded systems and flash-based storage devices.

When choosing a file system for a flash device, consider factors such as compatibility with the devices and operating systems you plan to use, performance requirements, and any specific features or optimizations you may need for your use case.


7.- ¿Qué aprendiste?

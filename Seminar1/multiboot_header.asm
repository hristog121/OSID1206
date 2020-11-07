bits 32	
	
section .multiboot_header

magic equ 0xe85250d6	    		
arch  equ 0		    		
	
header_start:
    dd magic                		
    dd arch                 		
    dd header_end - header_start 	
    ; checksum
    dd 0x100000000 - (magic + arch + (header_end - header_start))

    

  
    dw 0    ; type
    dw 0    ; flags
    dd 8    ; size
header_end:


;JORGE A. RUIZ
;CSIT    816
         BR      main        
num:     .EQUATE 8           ;LOCAL VARIABLES
n01:     .EQUATE 6           
n02:     .EQUATE 4           
n03:     .EQUATE 2           
n04:     .EQUATE 0           
;
;
main:    SUBSP   10,i        ;ALLOCATE MEMORY FOR VARIABLES
         STRO    msg1,d      ;DISPLAY
         DECI    num,s       ;READ INPUT
         LDA     num,s       ;LOAD INPUT
         ANDA    1,i         ;COMPUTE REMAINDER
         STA     n01,s       ;STORE
         LDA     num,s       ;LOA
         ASRA                ;DIVIDE BY 2
         ANDA    1,i         ;COMPUTE REMAINDER
         STA     n02,s       ;STORE
         LDA     num,s       ;LOAD INPUT
         ASRA                ;DIVIDE BY 2
         ASRA                ;DIVIDE BY 2
         ANDA    1,i         ;COMPUTE REMAINDER
         STA     n03,s       ;STORE REMAINDER
         LDA     num,s       ;LOAD INPUT
         ASRA                ;DIVIDE BY 2
         ASRA                ;DIVIDE BY 2
         ASRA                ;DIVIDE BY 2
         ANDA    1,i         ;COMPUTE REMAINDER
         STA     n04,s       ;STORE REMAINDER
         CHARO   '\n',i      ;NEW LINE
         DECO    num,s       ;DISPLAY ORIGINAL INPUT
         STRO    msg2,d      ;DISPLAY THE MESSAGE
         DECO    n04,s       ;DISPLAY THE BINARY NUMBER
         DECO    n03,s       
         DECO    n02,s       
         DECO    n01,s       
         ADDSP   10,i        ;DEALLOCATES
         STOP                ;STOPS
msg1:    .ASCII  "Enter number between 1 and 10: \x00"
msg2:    .ASCII  " in binary is \x00"
         .END                  
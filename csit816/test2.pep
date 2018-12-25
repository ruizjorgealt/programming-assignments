         BR      main        
big:     .EQUATE 8          ;LOCAL VARIABLES
i:       .EQUATE 6           
max:     .EQUATE 4           
sen:     .EQUATE 2           
n:       .EQUATE 0           
;
main:    SUBSP   12,i        ;ALLOCATES MEMORY
         STRO    msg1,d      
         DECI    max,s       
         STRO    msg2,d      
         DECI    sen,s       
         LDA     0,i         
         STA     i,s         
         STA     big,s       
L1:      LDA     i,s         ;COMPARES MAX TO COUNTER
         CPA     max,s       ;
         BRGE    endL        ;-
         STRO    msg3,d      ;SENTINNEL COMPARISON
         DECI    n,s         ;
         LDA     n,s         ;
         CPA     sen,s       ;
         BREQ    endL        ; -
         LDA     i,s         ;UPDATES THE COUNTER
         ADDA    1,i         ;
         STA     i,s         ;-
         LDA     n,s         ;UPDATES BIGGEST NUMBER
         CPA     big,s       ;
         BRLE    L1          ;
         STA     big,s       ;-
         BR      L1          ;
endL:    CHARO   '\n',i      ;END LOOP
         STRO    msg4,d      ;
         DECO    i,s         ;
         CHARO   '\n',i      ;   
         STRO    msg5,d      ;
         DECO    big,s       ;  
         CHARO   '\n',i      ;
         ADDSP   12,i        ;DEALLOCATES
         STOP                
msg1:    .ASCII  "Enter number of integers: \x00"
msg2:    .ASCII  "Enter sentinnel value: \x00"
msg3:    .ASCII  "Enter number: \x00"
msg4:    .ASCII  "Number of integers entered: \x00"
msg5:    .ASCII  "Maximum integer entered \x00"
         .END                  
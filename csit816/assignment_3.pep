;JORGE A RUIZ
;ASSIGNMENT 3
         BR      main        
j:       .EQUATE 6           ;LOCAL VARIABLES
i:       .EQUATE 4           
ch:      .EQUATE 2           
n:       .EQUATE 0           
;
main:    SUBSP   8,i         ;ALLOCATE MEMORY
         CHARI   ch,s        ;READ CHARACTER
         DECI    n,s         ;READ INTEGER
         LDA     0,i         ;LOAD ZERO
         STA     i,s         ;STORE IN I
L1:      LDA     i,s         ;LOAD I
         CPA     n,s         ;COMPARE TO N
         BRGE    endL        
         ADDA    1,i         ;ADD ONE TO I
         STA     i,s         ;STORE BACK INTO I
         LDA     0,i         ;LOAD ZERO
         STA     j,s         ;STORE INTO J
         CHARO   '\n',i      ;NEWLINE
L2:      LDA     j,s         ;LOAD J
         CPA     i,s         ;COMPARE TO I
         BRGE    L1          
         CHARO   ch,s        ;DISPLAY CHARACTER
         ADDA    1,i         ;ADD ONE TO J
         STA     j,s         ;STORE BACK INTO J
         BR      L2          ;BRANCH TO L2
endL:    ADDSP   8,i         ;DEALLOCATE MEMORY
         STOP                
         .END                  
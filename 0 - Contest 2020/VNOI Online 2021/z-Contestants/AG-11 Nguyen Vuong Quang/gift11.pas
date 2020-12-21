uses math;
Var A,B,C,F,E,ce,D:Array [0..1000000] of int64;I,j,k,m,n,p,q,l,r,mid,kk:longint;kq,t,ke,fe:int64;SL:longint;
Procedure quay(I,tc:longint;k:int64);Var j:longint;
Begin if I=N then Begin if (abs(k) mod 11)=0 then Inc(kq);Exit;end;
	For j:=1 to N do if d[j]=0 then
	Begin  d[j]:=1;
        if tc=0 then
        Begin
            if odd(B[j]) then quay(I+1,1,k+E[j]) else quay(I+1,0,k+E[j])
        End else
        Begin
            if odd(B[j]) then quay(I+1,0,k-E[j]) else quay(I+1,1,k-E[j]);
        End; d[j]:=0;
	End;
End;
Begin
    Assign(input,'gift11.inp');Reset(input);Assign(output,'gift11.out');Rewrite(output);
    Readln(SL);ce[0]:=1;
    For I:=1 to 10 do ce[I]:=Ce[I-1]*10;
    For Sl:=Sl downto 1 do
    Begin
    	Readln(N);kk:=0;kq:=0;
    	For I:=1 to N do
    	Begin t:=0;
            read(A[I]);k:=trunc(log10(A[I]))+1;ke:=Ce[k-1];fe:=A[I];
            //Writeln(ke);
    		For j:=1 to K do
            Begin if odd(j) then inc(t,Fe div ke) else dec(T,Fe div ke);fe:=Fe mod ke;ke:=ke div 10;End;
    		E[i]:=t;if odd(k) then B[I]:=1 else B[I]:=0;
            if not odd(k) then inc(kk);
    	End;t:=0;
    	if kk=n then
        Begin kq:=1;
            For i:=1 to N do t:=t+E[I];
            If (Abs(t) mod 11)=0 then
            Begin For I:=1 to N do kq:=kq*I;end else Begin Writeln(0);Continue;End;
            Writeln(kq);
        End;
    	Readln;
    	if (N<=10) then
        Begin
           Quay(0,0,0);
           Writeln(kq);
           Continue;
        End;
    End;
    Close(Input);Close(Output)
End.

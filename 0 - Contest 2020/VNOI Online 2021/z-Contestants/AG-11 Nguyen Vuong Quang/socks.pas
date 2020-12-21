uses math;
Var A,B,C:Array [0..1000000] of int64;I,j,k,m,n,p,q,l,r,mid:longint;kq,t:int64;
Begin
    Assign(input,'socks.inp');Reset(input);Assign(output,'socks.out');Rewrite(output);
    Readln(n,q);For I:=1 to N do Begin Read(A[i]);if A[I]=1 then inc(t);End;
    For I:=1 to N-1 do readln;
    if t>=2 then Writeln(1) else Writeln(0);
    For I:=1 to q do 
    Begin
    	readln(k);
    	if A[I]=1 then Begin dec(T);A[I]:=0;End 
    	else Begin inc(t);A[I]:=1;End;
    	if t>=2 then Writeln(1) else Writeln(0);
    End;
    Close(Input);Close(Output)
End.
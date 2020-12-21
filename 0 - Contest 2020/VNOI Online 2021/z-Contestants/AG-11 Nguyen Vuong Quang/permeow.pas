uses math;
type xy=record x,y:int64;end;
Var A,B,C:Array [0..1000000] of int64;I,j,k,m,n,p,q,l,r,mid:longint;kq,t:int64;
Procedure swap(var X,Y:longint); var tmp:longint;Begin tmp:=X;X:=Y;Y:=tmp;end;
Begin
  Assign(input,'permeow.inp');Reset(input);Assign(output,'permeow.out');Rewrite(output);
  readln(N);
  For I:=1 to N do read(A[i]);Readln;For i:=1 to N readln(A[I]);
  For I:=1 to N do
  Begin
  	For j:=1 to N do if A[j]=I then Begin k:=j;Break;
  	For j:=k-1 downto I do Begin swap(A[j],A[j+1]);inc(kq);kq:=kq mod 1000000007;end; 
  End; Writeln(kq);
  Close(Input);Close(Output)
End.
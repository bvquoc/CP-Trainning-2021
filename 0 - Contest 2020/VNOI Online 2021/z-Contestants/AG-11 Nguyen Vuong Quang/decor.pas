uses math;
type xy=record x,y:int64;end;
Var B,C:Array [0..1000000] of int64;I,j,k,m,n,p,q,l,r,mid:longint;kq,t:int64;S:Ansistring;
	A:Array [0..1000000] of xy;
Begin
  Assign(input,'Decor.inp');Reset(input);Assign(output,'Decor.out');Rewrite(output);
  Readln(N,m,k);readln(S);
  For I:=1 to M do Readln(A[I].x,A[I].y);
  For I:=1 to N do If S[I]='0' then C[I]:=C[I-1]+1 else C[I]:=C[I-1];
  If M=0 then
  Begin
  	kq:=0;q:=0;
  	For p:=1 to (N-k) do
  	Begin
      While ((C[q+1]-C[p-1])<=k) and (q<N) do inc(q); 
      if kq<(q-p+1) then Begin kq:=q-p+1;l:=p;r:=q;End;	
      if q=n then break;
  	End;
  	if kq=0 then Writeln(-1) else Writeln(l,' ',r);
	Exit;
  End;
  Close(Input);Close(Output)
End.

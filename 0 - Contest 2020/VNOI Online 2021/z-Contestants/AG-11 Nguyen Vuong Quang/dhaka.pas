uses math;
type xy=record x,y:int64;end;
Var A,B,C,Heap,Head,pos,H,F,S,den,cd:Array [0..1000000] of int64;I,j,k,m,n,p,q,l,r,mid,u,kk,ke:longint;kq,t:int64;
	G,FF:Array [0..1000000,0..6] of longint;
	E:Array [0..1000000] of xy;
Procedure quay(I,d:longint;kt:int64); var j,k:longint;
Begin den[i]:=1;
  if I=N then Begin den[I]:=0;if d>=ke then Begin kq:=min(kq,kt);End;exit;End;
  For j:=head[I]+1 to head[I+1] do 
  Begin
    if (den[E[j].x]=0) then 
    Begin
      For k:=1 to 5 do Begin inc(cd[k],G[E[j].x,k]);if (Cd[k]=1) and (G[E[j].x,k]=1) then d:=d+1;End;
      quay(E[j].x,d,kt+E[j].y);
      For k:=1 to 5 do Begin dec(cd[k],G[E[j].x,k]);if (Cd[k]=0) and (G[E[j].x,k]=1) then d:=d+1;End;
    End;
  End; den[I]:=0;
End;
Procedure Swap(X,Y:longint);Var z:Longint;Begin z:=pos[heap[x]];pos[heap[x]]:=pos[heap[y]];pos[heap[y]]:=z;z:=heap[x];heap[x]:=heap[y];heap[y]:=z;End;
Procedure up(I:longint);Var mid:longint;Begin mid:=I div 2;if mid<1 then exit;if F[heap[mid]]>F[heap[i]] then Begin swap(I,mid);Up(mid);End;End;
Procedure push(I:longint);Begin if pos[I]=0 then Begin inc(q);heap[q]:=I;pos[I]:=q;End;up(pos[I]);End;
Procedure down(I:longint);Var mid:longint;
Begin mid:=I*2;if mid>q then exit;if (q>mid) and (F[heap[mid]]>F[heap[mid+1]]) then inc(mid);
	if (F[heap[mid]]<F[heap[I]]) then Begin swap(I,mid);down(mid);end;End;
Function pop:int64;Begin pop:=heap[1];heap[1]:=heap[q];pos[heap[1]]:=1;heap[q]:=0;dec(q);if q>1 then down(1);End;
Begin
  Assign(input,'Dhaka.inp');Reset(input);Assign(output,'Dhaka.out');Rewrite(output);
  Readln(N,M,ke,l);kq:=maxlongint*maxlongint;
  For I:=1 to N do Begin Read(S[I]);For j:=1 to S[I] do Begin read(q);G[I,q]:=1;End;End;
  For I:=1 to M do Begin Readln(A[I],B[I],C[i]);Inc(head[A[I]]);Inc(head[b[I]]);End;
  For I:=1 to N+1 do Begin Head[I]:=head[I-1]+head[I];F[I]:=maxlongint*maxlongint;end;
  For I:=1 to M do
  Begin
  	E[Head[A[i]]].x:=B[I];E[Head[A[I]]].y:=C[I];Dec(head[A[I]]);
  	E[Head[B[I]]].x:=A[I];E[head[B[I]]].y:=C[I];dec(head[B[I]]);
  End;F[1]:=0;
  q:=0;
  if l=0 then 
  Begin push(1);
  	While true do
  	Begin if q<=0 then break;
  		u:=pop;den[u]:=1;
  		If (u=N) or (U=0) then Break;
  		For I:=head[U]+1 to head[U+1] do
  		Begin
  			if (den[E[I].x]=0) and ((F[E[I].x])>(F[u]+E[I].y)) then
  			Begin F[E[I].x]:=F[u]+E[I].y;push(E[I].x);End;
  		End;
  	End;
    if F[N]=(maxlongint*maxlongint) then Writeln(-1) else Writeln(F[N]);
  End else
  if N<=10 then 
  Begin kk:=0;For I:=1 to 5 do cd[I]:=G[1,I];
    quay(1,S[1],0);if kq=(maxlongint*maxlongint) then Writeln(-1) else Writeln(kq);
  End;
  Close(Input);Close(Output)
End.

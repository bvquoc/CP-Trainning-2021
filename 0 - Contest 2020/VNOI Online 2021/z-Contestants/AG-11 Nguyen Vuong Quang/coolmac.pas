uses math;
type xy=record x,y:longint; end;
Var B,C,H,G,F,E:Array [0..200000] of int64;I,j,k,m,n,p,q:longint;kq,t:int64;
    A:Array [0..200000] of xy;
procedure qs(L,R:longint);Var x,y:longint;tmp,w:xy;
Begin x:=l;y:=R;w:=A[(L+R) div 2];
       repeat
        While (A[x].x<W.x) do inc(x);
        While (A[Y].x>W.x) do dec(Y);
        If X<=y then Begin tmp:=A[x];A[x]:=A[y];A[y]:=tmp;INc(X);dec(y);End;
       Until x>y;
       if x<R then Qs(X,R);If Y>L then Qs(L,Y);
End;
Begin
       Assign(Input,'Coolmac.inp');Reset(input);
       Assign(output,'Coolmac.out');Rewrite(output);
       Readln(N);For I:=1 to N do readln(A[I].x,A[I].y);
       k:=100000;
       Readln(m);For i:=1 to M do Begin Read(p);k:=min(k,p);End;
       qs(1,N);I:=1;p:=0;q:=0;
       While A[I].y<k do inc(I);
       While (A[I].x<=k) and (i<=N) do Begin q:=max(A[I].y,q);inc(I);End;
       if q=0 then Begin Write(-1);exit;End;
       While (I<=N) do
       Begin
            if A[I].x>q then Begin Write(-1);exit;end;
            inc(kq);p:=q;
            While (A[I].x<=q) And (I<=N) do
            Begin p:=max(p,A[I].y);inc(I);End;
            q:=p;
            If q>=100000 then Begin Write(kq+1);Exit;End;
       End;
       Writeln(-1);
       //Close(input);Close(output);
End.

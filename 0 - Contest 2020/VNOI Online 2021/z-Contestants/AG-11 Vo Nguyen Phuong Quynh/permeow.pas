const modulo=1000000007;
var i,n,j,t:longint;
    res: int64;
    dk:boolean;
    a,b: array [0..1000000] of longint;
procedure sub2;
   var i,j,t:longint;
   begin
      for i:=1 to n-1 do
         for j:=i+1 to n do begin
            inc(res);
            t:=b[i];
            b[i]:=b[j];
            b[j]:=i;
         end;
      res:=(res*(res+1) div 2) mod modulo;
      write(res);
      close(input); close(output); halt;
   end;
Begin
   assign(input,'permeow.inp'); reset(input);
   assign(output,'permeow.out'); rewrite(output);
   readln(n);
   dk:=true;
   for i:=1 to n do read(a[i]);
   for i:=1 to n do begin
      read(b[i]);
      if a[i]<>b[i] then dk:=false;
   end;
   if not dk then sub2;
   for i:=1 to n-1 do
      for j:=i+1 to n do
         if a[j]<a[i] then begin
            res:=res+1;
            res:=res mod modulo;
            t:=a[1];
            a[i]:=a[j];
            a[j]:=t;
         end;
   write(res);
   close(input); close(output);
End.

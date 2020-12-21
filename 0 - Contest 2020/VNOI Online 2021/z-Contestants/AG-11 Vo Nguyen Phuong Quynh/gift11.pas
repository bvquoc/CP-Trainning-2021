const modulo=998244353;
var t,i,j,dk1,x:longint;
    res:int64;
    n,a: array [0..1000] of longint;
    d: array [0..1000] of boolean;
    s: array [0..100,0..5000] of string;
procedure check(k:longint);
   var i,tt,m:longint;
       st: string;
   begin
      st:='';
      for i:=1 to n[k] do
         st:=st+s[k,a[i]];
      m:=length(st);
      tt:=0;
      for i:=1 to m do
         if i mod 2 = 1 then inc(tt,ord(st[i])-48)
         else dec(tt,ord(st[i])-48);
      if abs(tt) mod 11=0 then inc(res);
      res:=res mod modulo;
   end;
procedure try(k,i:longint);
   var j:longint;
   begin
      for j:=1 to n[k] do
         if d[j] then begin
            a[i]:=j;
            d[j]:=false;
            if i=n[k] then check(k)
            else try(k,i+1);
            d[j]:=true;
         end;
   end;

procedure sub1;
   var i:longint;
   begin
      for i:=1 to t do begin
         res:=0;
         fillchar(d,sizeof(d),true);
         try(i,1);
         writeln(res);
      end;
      close(input); close(output); halt;
   end;

procedure sub2;
   var i,j,m:longint;
       tt:int64;
       st: ansistring;
   begin
      for i:=1 to t do begin
         res:=0; st:=''; tt:=0;
         for j:=1 to n[i] do
            st:=st+s[i,j];
         m:=length(st);
         tt:=0;
         for j:=1 to m do
            if j mod 2 = 1 then inc(tt,ord(st[j])-48)
            else dec(tt,ord(st[j])-48);
         if abs(tt) mod 11=0 then begin
            res:=1;
            for j:=2 to n[i] do res:=(res*j) mod modulo;
         end;
         writeln(res);
      end;
      close(input); close(output); halt;
   end;
Begin
   assign(input,'gift11.inp'); reset(input);
   assign(output,'gift11.out'); rewrite(output);
   readln(t);
   dk1:=0;
   for i:=1 to t do begin
      readln(n[i]); inc(dk1,n[i]);
      for j:=1 to n[i] do begin
         read(x);
         str(x,s[i,j]);
      end;
   end;
   if dk1<=13 then sub1;
   sub2;
   close(input); close(output);
End.
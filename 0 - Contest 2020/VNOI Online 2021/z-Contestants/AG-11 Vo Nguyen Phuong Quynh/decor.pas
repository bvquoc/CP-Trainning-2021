uses math;
var l,r,n,m,k,i:longint;
    s: ansistring;
    a,b,sb:array [0..1000000] of longint;
procedure sub1;
   var i,le:longint;
   begin
      le:=0;
      for i:=1 to n do
         if s[i]='0' then a[i]:=0
         else begin
            a[i]:=a[i-1]+1;
            if a[i]>le then begin
               le:=a[i];
               r:=i;
               l:=i-le+1;
            end;
         end;
      if le=0 then write('-1') else
      write(l,' ',r);
      close(input); close(output); halt;
   end;
function find(st,d,c:longint):longint;
   var g:longint;
   begin
      while d<c do begin
         g:=(d+c+1) div 2;
         if b[g]-b[st]>k then c:=g-1 else d:=g;
      end;
      exit(d);
   end;
procedure sub2;
   var i,x:longint;
   begin
      for i:=1 to n do begin
         if s[i]='0' then b[i]:=b[i-1]+1
         else b[i]:=b[i-1];
      end;
      l:=0; r:=0;
      for i:=1 to n-1 do begin
         x:=find(i-1,i+1,n);
         if (b[x]-b[i-1]<=k) and (x-i>r-l) then begin
            l:=i;
            r:=x;
         end;
      end;
      if (l=0) and (r=0) then write('-1') else
      write(l,' ',r);
      close(input); close(output); halt;
   end;
Begin
   assign(input,'decor.inp'); reset(input);
   assign(output,'decor.out'); rewrite(output);
   readln(n,m,k);
   readln(s);
   for i:=1 to m do readln(a[i],b[i]);
   if (m=0) and (k=0) then sub1;
   if (m=0) then sub2;
   write('-1');
   close(input); close(output);
End.

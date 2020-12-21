uses math;
var x,st,n,m,i,t,res:longint;
    r,l,d: array [0..1000000] of longint;
procedure quicksort(dau,cuoi: longint);
   var i,j,k: longint;
       t1,t2,t3:longint;
   begin
      i:=dau; j:=cuoi;
      k:=l[(dau+cuoi) div 2];
      repeat
         begin
            while l[i]<k do inc(i); while l[j]>k do dec(j);
            if i<=j then
               begin
                  t1:=l[i]; l[i]:=l[j]; l[j]:=t1;
                  t2:=r[i]; r[i]:=r[j]; r[j]:=t2;
                  inc(i); dec(j);
               end;
         end;
      until i>j;
      if dau<j then quicksort(dau,j);
      if cuoi>i then quicksort(i,cuoi);
   end;
Begin
   assign(input,'coolmac.inp'); reset(input);
   assign(output,'coolmac.out'); rewrite(output);
   readln(m);
   t:=100000;
   for i:=1 to m do readln(l[i],r[i]);
   readln(n);
   for i:=1 to n do begin
      read(x);
      t:=min(x,t);
   end;
   quicksort(1,m);
   for i:=1 to m do
      if l[i]>t then begin
         st:=i-1;
         break;
      end;
   res:=m-st+1;
   for i:=st to m-1 do
      if r[i]< l[i+1] then begin
         res:=-1;
         break;
      end;
      if r[i]>=r[i+1] then dec(res);
   write(res);
   close(input); close(output);
End.
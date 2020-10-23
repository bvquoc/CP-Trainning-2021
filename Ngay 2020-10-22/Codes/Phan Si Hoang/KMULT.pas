var     X:array[1..10000]of integer;
        A:array[1..10000]of longint;
        i,n,k:longint;
procedure QuayLui(i:integer);
Var     j,sum,r:longint;
begin
        for j:=0 to 1 do
        begin
                X[i]:=j;
                If (i=n) then
                begin
                        Sum:=0;
                        for r:=1 to n do
                        Begin
                                If X[r]=0 then Sum:=Sum+A[r];
                                If X[r]=1 then Sum:=Sum-A[r];
                        end;
                        If Sum mod k = 0 then
                        begin
                                Write(1);
                                for r:=2 to n do
                                Begin
                                        If X[r]=0 then write('+');
                                        If X[r]=1 then write('-');
                                end;
                                Halt;
                        end;
                end
                else QuayLui(i+1);
        end;
end;
Begin
        Assign(input,'KMULT.inp');reset(input);
        Assign(output,'KMULT.out');rewrite(output);
        Readln(n,k);
        For i:=1 to n do Read(A[i]);
        QuayLui(1);
        Write(0);

End.



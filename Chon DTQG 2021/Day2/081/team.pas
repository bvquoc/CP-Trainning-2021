uses crt;
var a: array[1..10000000] of int64;
    n: integer;
    k: int64;
    i: longint;
    f: text;
procedure input;
begin
        assign (f,'TEAM.INP');
        reset  (f);
        readln (f,n,k);
        for i:=1 to n do read (f,a[i]);
        close (f);
end;
procedure solve;
begin
        repeat
                        for i:=1 to n do
                                begin
                                        if a[i] > k then break;
                                        if a[i] <= k then k:= k-a[i];
                                end;

        until k < a[i];
end;
procedure output;
begin
        assign (f,'TEAM.OUT');
        rewrite (f);
        write (f,k);
        close (f);
end;
begin
        input;
        solve;
        output;
        write (k);
end.

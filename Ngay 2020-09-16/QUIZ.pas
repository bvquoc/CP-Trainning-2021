const
    fi = 'QUIZ.INP';
    fo = 'QUIZ.OUT';
    maxN = round(1e6);

var d: array[1..maxN] of longint;

procedure Init;
var i, j: longint;
begin
    fillchar(d, sizeof(d), 0);
    for i := 1 to trunc(sqrt(maxN)) do
    begin
        inc(d[i*i]);
        j := i+1;
        while (i*j <= maxN) do
        begin
            d[i*j] := d[i*j] + 2;
            inc(j);
        end;
    end;
end;

procedure Solve;
var f, g: text;
    i, res, n, k: longint;
begin
    Init;
    assign(f, fi); reset(f);
    assign(g, fo); rewrite(g);
    readln(f, n, k);
    {
    res := 0;
    for i := 1 to n-1 do
        if (d[i] = k) then inc(res);
    writeln(g, res);
    }
    for i := 1 to 1000000 do
        writeln(g, i, ' ', d[i]);
    close(f); close(g);
end;

procedure GenTest;
var f, g: text;
    i, n, t, k, res: longint;
    s: string;
begin
    randomize;
    n := 5;
    Init;
    for t := 1 to 50 do
    begin
        str(t, s);
        if (t < 10) then s := '0' + s;
        assign(f, s + '.i'); rewrite(f);
        assign(g, s + '.o'); rewrite(g);
        n := n + random(t*t);
        if (n > maxN) then n := maxN;
        if (t <= 20) then k := d[random(n div 2) + 1]
        else k := d[random(n div 4) + 1];
        writeln(f, n, ' ', k);
        res := 0;
        for i := 1 to n-1 do
            if (d[i] = k) then inc(res);
        writeln(g, res);
        close(f); close(g);
    end;
end;

begin
    Solve;
    //GenTest;
end.

# V0.4
**main.cpp** <br/>

CPU - Intel Core I5-4690 3.50GHz
RAM - 16GB
HDD - Seagate Desktop ST3500418AS 3Gb/s

**Greičiai release'o**

**<p>Greičio testavimas failo su *100* eilučių<p>** 
Failo kurimas: *0.0012465 s*. <br/>
Nuskaitymas duomenų: *0.0005486 s*. <br/>
Rušiavimas į du skirtingus vektorius: *0.2.23e-05 s*.<br/>
Duomenų išvedimas į 2 failus: *0.0005053 s*. <br/>

**<p>Greičio testavimas failo su *1000* eilučių<p>** 
Failo kurimas: *0.0046764 s*. <br/>
Nuskaitymas duomenų: *0.0040105 s*. <br/>
Rušiavimas į du skirtingus vektorius: *0.000223s*.<br/>
Duomenų išvedimas į 2 failus: *0.0023247 s*.<br/>

**<p>Greičio testavimas failo su *10000* eilučių<p>** 
Failo kurimas: *0.0427399 s*. <br/>
Nuskaitymas duomenų: *0.0.0376422 s*. <br/>
Rušiavimas į du skirtingus vektorius: *0.0016462s*.<br/>
Duomenų išvedimas į 2 failus: *0.0152214 s*. <br/>

**<p>Greičio testavimas failo su *100000* eilučių<p>** 
Failo kurimas: *0.406029 s*. <br/>
Nuskaitymas duomenų: *0.387604 s*. <br/>
Rušiavimas į du skirtingus vektorius: *0.0172279 s*.<br/>
Duomenų išvedimas į 2 failus: *0.160913 s*. <br/>

**<p>Greičio testavimas failo su *1000000* eilučių<p>** 
Failo kurimas: *4.0014 s*. <br/>
Nuskaitymas duomenų: *3.84238 s*. <br/>
Rušiavimas į du skirtingus vektorius: *0.197207 s*.<br/>
Duomenų išvedimas į 2 failus: *1.61153 s*. <br/>

**main2.cpp**
<p>Šioje versijoje nenaudojami yra vektoriai blogiems ir geriems pažymiams. Duomenys yra rušiuojami tuo pačiu metu kai yra išvedinejami į du failus, tai čia truputi greitesnis programos veikimas.<p>

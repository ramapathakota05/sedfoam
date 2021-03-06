/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2016 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/
if (runTime.outputTime())
{
    if (writeTau == 1)
    {
        Taua = rhoa*(alpha*nuEffa+nuFra)*dev(fvc::grad(Ua));
        Taub = rhob*(scalar(1.0)-alpha)*nuEffb*dev(fvc::grad(Ub));

        Taua.write();
        Taub.write();
    }
    if (granularRheology.on())
    {
        alphaPlastic.write();
        delta.write();
        pa.write();
    }
    if (kineticTheory.on())
    {
        pa.write();
    }
    if (SUSlocal)
    {
        SUS.write();
    }
    pff.write();
    runTime.write();
}

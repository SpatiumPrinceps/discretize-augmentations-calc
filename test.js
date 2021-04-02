const correct = {
    "daily": {
        "relics": 600,
        "pristines": 21,
        "matrices": 3,
        "pages": 6.29
    },
    "mistAttunements": [
        {
            "id": 298,
            "name": "Mist Attunement 4",
            "title": "Fractal God",
            "relics": 55000,
            "pristines": 2000,
            "matrices": 300,
            "journals": 0,
            "days": 222,
            "standard": {
                "daysForRelics": 91,
                "daysForJournals": 0,
                "daysForMatrices": 100,
                "daysForPristines": 95
            },
            "convert": {
                "pristinesToRelics": 189,
                "relicsToMatrices": 72,
                "pagesToJournals": 0
            },
            "total": {
                "relics": 160000,
                "pristines": 3200,
                "matrices": 750,
                "journals": 24
            }
        },
        {
            "id": 296,
            "name": "Mist Attunement 3",
            "title": "Fractal Champion",
            "relics": 45000,
            "pristines": 0,
            "matrices": 225,
            "journals": 16,
            "days": 140,
            "standard": {
                "daysForRelics": 75,
                "daysForJournals": 2,
                "daysForMatrices": 75,
                "daysForPristines": 0
            },
            "convert": {
                "pristinesToRelics": 714,
                "relicsToMatrices": 30,
                "pagesToJournals": 0
            },
            "total": {
                "relics": 105000,
                "pristines": 1200,
                "matrices": 450,
                "journals": 24
            }
        },
        {
            "id": 297,
            "name": "Mist Attunement 2",
            "title": "Fractal Prodigy",
            "relics": 35000,
            "pristines": 1200,
            "matrices": 150,
            "journals": 0,
            "days": 84,
            "standard": {
                "daysForRelics": 58,
                "daysForJournals": 0,
                "daysForMatrices": 50,
                "daysForPristines": 57
            },
            "convert": {
                "pristinesToRelics": 42,
                "relicsToMatrices": 0,
                "pagesToJournals": 0
            },
            "total": {
                "relics": 60000,
                "pristines": 1200,
                "matrices": 225,
                "journals": 8
            }
        },
        {
            "id": 299,
            "name": "Mist Attunement 1",
            "title": "Fractal Savant",
            "relics": 25000,
            "pristines": 0,
            "matrices": 75,
            "journals": 8,
            "days": 35,
            "standard": {
                "daysForRelics": 41,
                "daysForJournals": 1,
                "daysForMatrices": 25,
                "daysForPristines": 0
            },
            "convert": {
                "pristinesToRelics": 525,
                "relicsToMatrices": 0,
                "pagesToJournals": 0
            },
            "total": {
                "relics": 25000,
                "pristines": 0,
                "matrices": 75,
                "journals": 8
            }
        }
    ]
}

function arrayEquals(a, b) {
    return Array.isArray(a) &&
        Array.isArray(b) &&
        a.length === b.length &&
        a.every((val, index) => val === b[index]);
}

function test() {
    const calced = calc_internal();
    if (JSON.stringify(calced) == JSON.stringify(correct)) {
        document.getElementById("test").style.background = "green";
    } else {
        document.getElementById("test").style.background = "red";
        console.log(calced);
    }
}
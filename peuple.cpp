#include "peuple.h"
#include <chrono>
#include <random>
#include "sexe.h"
#include <QDebug>

Peuple::Peuple(QString id, QString sousGroupe):m_Peuple(id), m_SousGroupe(sousGroupe)
{
    if ( m_SousGroupe == "") {
        if ( id == Peuple::ESCARTE) {
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::default_random_engine generator(seed);
            std::uniform_int_distribution<int> distribution(0, 5);
            int val  = distribution(generator);
            switch(val) {
                case 0 :case 1 :case 2 :case 3 : this->m_SousGroupe =Peuple::OCCIDENTIN; break;
                case 5 : this->m_SousGroupe =Peuple::DORKADE; break;
                case 4 : this->m_SousGroupe =Peuple::ARAGON; break;
            }
        }
    }
}

QString Peuple::ALFARIQN = "Alfariqn";
QString Peuple::SAABI = "Saabi";
QString Peuple::AGALANTHEEN = "Agalanthéen";
QString Peuple::SHIRADIM = "Shiradim";
QString Peuple::ESCARTE = "Escarte";
QString Peuple::OCCIDENTIN = "Occidentin";
QString Peuple::DORKADE = "Dorkade";
QString Peuple::ARAGON = "Aragon";

QList<QString> Peuple::PEUPLES = {
    Peuple::SAABI,
    Peuple::SHIRADIM,
    Peuple::ESCARTE,
    Peuple::AGALANTHEEN,
    Peuple::ALFARIQN
};

QList<QString> Peuple::SOUS_GROUPE_ESCARTE = {
    Peuple::OCCIDENTIN,
    Peuple::DORKADE,
    Peuple::ARAGON
};

QString Peuple::GenererNom(QString peuple, QString sexe, QString sousensemble)
{
    // construct a trivial random generator engine from a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, 99999999999999999);

    if ( peuple == Peuple::SHIRADIM) {

        if ( sexe == Sexe::MALE) {
            QString nomTotal = Peuple::PRENOMS_SHIRADIM_MALES[distribution(generator) % Peuple::PRENOMS_SHIRADIM_MALES.length()] + " ";
            if(distribution(generator)%4 == 0) {
                // fille de [mère] => quand le père est inconnu, que l'enfant est un batard etc
                nomTotal += "Bat " + Peuple::PRENOMS_SHIRADIM_FEMELLES[distribution(generator) % Peuple::PRENOMS_SHIRADIM_FEMELLES.length()];
            } else {
                nomTotal += "Bar " + Peuple::PRENOMS_SHIRADIM_MALES[distribution(generator) % Peuple::PRENOMS_SHIRADIM_MALES.length()];
            }
            return nomTotal;
        } else {
            QString nomFem = Peuple::PRENOMS_SHIRADIM_FEMELLES[distribution(generator) % Peuple::PRENOMS_SHIRADIM_FEMELLES.length()] + " ";
            if(distribution(generator)%4 == 0) {
                // fille de [mère] => quand le père est inconnu, que l'enfant est un batard etc
                nomFem += "Bat " + Peuple::PRENOMS_SHIRADIM_FEMELLES[distribution(generator) % Peuple::PRENOMS_SHIRADIM_FEMELLES.length()];
            } else {
                nomFem += "Bar " + Peuple::PRENOMS_SHIRADIM_MALES[distribution(generator) % Peuple::PRENOMS_SHIRADIM_MALES.length()];
            }
            return nomFem;
        }
    } else if ( peuple == Peuple::SAABI) {

        if ( sexe == Sexe::MALE) {
            QString nomTotal = Peuple::PRENOMS_SAABI_MALES[distribution(generator) % Peuple::PRENOMS_SAABI_MALES.length()] + " ";
            if(distribution(generator)%2 == 0) {
                nomTotal += Peuple::NOMS_SAABI[distribution(generator) % Peuple::NOMS_SAABI.length()];
            } else {
                nomTotal += "Ibn " + Peuple::PRENOMS_SAABI_MALES[distribution(generator) % Peuple::PRENOMS_SAABI_MALES.length()];
            }
            return nomTotal;
        } else {
            QString nomFem = Peuple::PRENOMS_SAABI_FEMELLES[distribution(generator) % Peuple::PRENOMS_SAABI_FEMELLES.length()] + " ";
            if(distribution(generator)%2 == 0) {
                nomFem += Peuple::NOMS_SAABI[distribution(generator) % Peuple::NOMS_SAABI.length()];
            } else {
                nomFem += "Bint " + Peuple::PRENOMS_SAABI_FEMELLES[distribution(generator) % Peuple::PRENOMS_SAABI_FEMELLES.length()];
            }
            return nomFem;
        }
    } else if ( peuple == Peuple::ESCARTE ) {
        if ( sousensemble == "") {
            switch(distribution(generator) % 3) {
            case 0 : sousensemble=Peuple::OCCIDENTIN; break;
            case 1 : sousensemble=Peuple::DORKADE; break;
            case 2 : sousensemble=Peuple::ARAGON; break;
            }
        }
        if ( sousensemble == Peuple::OCCIDENTIN) {
            return ( (sexe == Sexe::MALE) ?
                     Peuple::PRENOMS_OCCIDENTIN_MALES[distribution(generator) % Peuple::PRENOMS_OCCIDENTIN_MALES.length()] :
                     Peuple::PRENOMS_OCCIDENTIN_FEMELLES[distribution(generator) % Peuple::PRENOMS_OCCIDENTIN_FEMELLES.length()] )
                    + " " +
                    Peuple::NOMS_OCCIDENTIN[distribution(generator) % Peuple::NOMS_OCCIDENTIN.length()];
        } else if (sousensemble == Peuple::ARAGON) {
            return ( (sexe == Sexe::MALE) ?
                     Peuple::PRENOMS_ARAGON_MALES[distribution(generator) % Peuple::PRENOMS_ARAGON_MALES.length()] :
                     Peuple::PRENOMS_ARAGON_FEMELLES[distribution(generator) % Peuple::PRENOMS_ARAGON_FEMELLES.length()] )
                    + " " +
                    Peuple::NOMS_ARAGON[distribution(generator) % Peuple::NOMS_ARAGON.length()];
        } else if (sousensemble == Peuple::DORKADE) {
            return ( (sexe == Sexe::MALE) ?
                     Peuple::PRENOMS_DORKADE_MALES[distribution(generator) % Peuple::PRENOMS_DORKADE_MALES.length()] :
                     Peuple::PRENOMS_DORKADE_FEMELLES[distribution(generator) % Peuple::PRENOMS_DORKADE_FEMELLES.length()] )
                    + " " +
                    Peuple::NOMS_DORKADE[distribution(generator) % Peuple::NOMS_DORKADE.length()];
        }
    }

    return "pas de nom";
}

QVector<QString> Peuple::PRENOMS_SHIRADIM_MALES = {
    "Abel", "Abraham", "Aaron", "Abecassis", "Abitbol", "Abitboul", "Avraham", "Ibrahim", "Ari", "Ariel",
    "Baru'kh", "Binyamin", "Boaz", "Daniel", "David", "Eli", "Ezekiel", "Ezra", "Ebenazar", "Gad", "Hillel", "Ioranan",
    "Isaac", "Isaiah", "Levi", "Matitiaou", "Mena'khem", "Morde'khai", "Mogda", "Nathan", "Noam", "Reuven",
    "Shaül", "Shimon", "Shiran", "Shlomo", "Uriel", "Yaacov", "Yeremiah", "Yergad", "Yonathan", "Yosef",
    "Adinah",  	"Adir",  	"Adoniyah",  	"Aharon",
    "Akiba",  	"Akiva",  	"Alon",  	"Amaryahu",
    "Amichai",  	"Arik",  	"Aryeh",  	"Asaf",
    "Asher",  	"Avi",  	"Avidan",  	"Avihu",
    "Avimelekh",  	"Aviram",  	"Avishai",  	"Avishay",
    "Aviv",  	"Avner",  	"Avraham",  	"Avram",
    "Avshalom",  	"Ayal",  	"Azaryah",  	"Azazyahu",
    "Barukh",  	"Belshatzzar",  	"Benayahu",  	"Binyamin",
    "Chaim",  	"Chananyah",  	"Chanokh",  	"Chavaqquq",
    "Chayim",  	"Chayyim",  	"Chizqiyahu",  	"Daniyyel",
    "Daryawesh",	"Dekel",	"Delayahu",	"Deror",
    "Dori",  	"Doron",  	"Dov",  	"Dror",
    "Efraim",  	"Efrayim",  	"Eiran",  	"Eitan",
    "Elifalet",  	"Elifelet",  	"Elior",  	"Eliyahu",
    "Eliyyahu",  	"Elkan",  	"Erez",  	"Esaw",
    "Eyal",  	"Eytan",  	"Gavriel",  	"Gedalyahu",
    "Gemaryahu",  	"Gilad",  	"Haim", 	"Hayim",
    "Hayyim",  	"Hebel",  	"Hevel",  	"Hyam",
    "Idan",  	"Itai",  	"Itamar",  	"Ittay",
    "Itzhak",  	"Iyov",  	"Iyyov",  	"Keinan",
    "Kenanyahu",  	"Kfir",  	"Koresh",  	"Lavi",
    "Lewi",  	"Machli",  	"Malachi",  	"Maor",
    "Matan",  	"Mattanyahu",  	"Mattithyahu",  	"Mattityahu",
    "Meir",  	"Melek",  	"Menachem",  	"Menashe",
    "Menashsheh",  	"Meshulam",  	"Mikhah",  	"Mordechai",
    "Mordokhay",  	"Moshe",  	"Nachum",  	"Nadav",
    "Natan",	"Nechemyah",  	"Netanyahu",  	"Nir",
    "Niv",  	"Noach",  	"Noam",	"Ofek",  "Ophyr",
    "Ofer",  	"Ofrah",  	"Oren",  	"Osher",
    "Ovadia",  	"Ovadyah",  	"Oved",  	"Raanan",
    "Reuven",  	"Ronen",  	"Sagi",  	"Shai",
    "Shalom",  	"Shelomoh",  	"Sheraga",  	"Shet",
    "Shimon",  	"Shimshon",  	  	"Shmuel",
    "Shraga",  	"Tamir",  	"Terach",  	"Tomer",
    "Toviyyah",  	"Tuvya",  	"Tzafrir",  	"Tzefanyah",
    "Tzidkiyahu",  	"Tzion",  	"Tzivah",  	"Tzvi",
    "Udi",  	"Uri",  	"Uriyah",  	"Uzi",
    "Uzziyyah",  	"Yaakov",  	"Yachin",  	"Yadon",
    "Yair",  	"Yakov",  	"Yaniv",  	"Yared",
    "Yaron",  	"Yechezkel",  	"Yedidyah",  	"Yefet",
    "Yehiel",  	"Yehochanan",  	"Yehonatan",  	"Yehoram",
    "Yehoshafat",  	"Yehoshua",  	"Yehoyakhin",  	"Yehoyakim",
    "Yehudah",  	"Yehudi",  	"Yered",  	"Yeriyahu",
    "Yeshua",  	"Yiftach",  	"Yirmiyahu",  	"Yishai",
    "Yishmeray",  	"Yissakhar",  	"Yitzhak",  	"Yoav",
    "Yochanan",  	"Yoel",  	"Yonah",  	"Yonatan",
    "Yoni",	"Yoram",  	"Yosef",  	"Yoshiyahu",
    "Yotam",  	"Zeev",  	"Zekharyah",  	"Zev",
    "Zevadyah",  	"Zevulun",  	"Zvi"


};

QVector<QString> Peuple::PRENOMS_SHIRADIM_FEMELLES = {
    "Abehassera", "Abehcera", "Abehsera", "Abehserra", "Abehsira", "Abehssera", "Abihsera",
    "Abihsira", "Abihssera", "Abihssira", "Abissera", "Boussera", "Ariel", "Dara", "Devrah",
    "Esther", "Hannah", "Leah", "Maya", "Miriam", "Naomi", "Oprah", "Rachel", "Ruth", "Sarah", "Shaïna",
    "Shirel", "Shayna", "Shirel", "Susanna", "Tiamar", "Yudith", "Zelda",
    "Achinoam",  	"Adara",  	"Adena",  	"Adi",
    "Adva",  	"Agam",  	"Ahava",  	"Ahuva",
    "Aliza",  	"Almog",  	"Alona",  	"Asenat",
    "Ashtoret",  	"Atalia",  	"Atalyah",  	"Atara",
    "Avia",  	"Avigail",  	"Avigayil",  	"Avishag",
    "Aviva",  	"Aviya",  	"Aviyah",  	"Ayala",
    "Ayelet",  	"Ayla",  	"Bashe",  	"Basmat",
    "Basya",  	"Bat-sheva",  	"Batel",  	"Batsheva",
    "Batya",  	"Batyah",  	"Beracha",  	"Bityah",
    "Bosmat",  	"Bracha",  	"Chaggit",  	"Chanah",
    "Channah",  	"Chava",  	"Chawwah",  	"Chaya",
    "Cheftzi-bah",  	"Chesed",  	"Chuldah",  	"Dafna",
    "Dalit",	"Dalya",	"Danya",	"Dassah",
    "Derorit",	"Devorah",	"Dikla",	"Diklah",
    "Dor",  	"Dorit",  	"Drorit",  	"Dvorah",
    "Ednah",  	"Efrat",  	"Elah",  	"Eliora",
    "Elisheva",  	"Gal",  	"Galit",  	"Geula",
    "Gilah",  	"Gili",  	"Hadar",  	"Hadas",
    "Hagit",  	"Hava",  	"Hed",  	"Herut",
    "Hila",  	"Hodiyah",  	"Idriya",  	"Ilana",
    "Ilanit",  	"Inbal",  	"Inbar",  	"Irit",
    "Jaffe",  	"Kelila",  	"Keren",  	"Keshet",
    "Liat",  	"Libi",  	"Lihi",  	"Lior",
    "Liora",  	"Liorit",  	"Liron",  	"Livna",
    "Livnat",  	"Maayan",  	"Machalat",  	"Machlah",
    "Malka",	"Margalit",  	"Margalita",  	"Marganita",
    "Marni",  	"Maytal",  	"Meira",  	"Meirit",
    "Meital",  	"Menuha",  	"Merav",  	"Mica",
    "Mikhal",  	"Mikhayhu",  	"Nahal",  	"Nava",
    "Neta",  	"Nissa", 	"Nitza",  	"Nitzan",
    "Noa",	"Noga",  	"Noy",  	"Noya",
    "Nurit",  	"Ofir",  	"Ofra",  	"Or",
    "Orah",  	"Ori",  	"Orit",  	"Orli",
    "Orly",  	"Orpah",  	"Ravid", 	"Raz",
    "Raziela",  	"Reut",  	"Riva",  	"Rivka",
    "Rivqah",  	"Roni",  	"Rotem",  	"Sagit",
    "Sapir",  	"Sarit",  	"Shachar",  	"Shahar",
    "Shaked",  	"Shalev",  	"Shamira",  	"Shani",
    "Shifra",  	"Shir",  	"Shira",  	"Shiri",
    "Shlomit",  	"Shoshana",  	"Shoshannah",  	"Shulamit",
    "Shulamith",  	"Shulammi",  	"Shulammite",  	"Sigal",
    "Sigalit",  	"Simcha",  	"Smadar",  	"Tahlia",
    "Tal",  	"Tali",  	"Talya",  	"Tamar",
    "Tehila", 	"Tikva",  	"Tirtzah",  	"Tova",
    "Tovah",  	"Tovia",  	"Tziporah",  	"Tzipporah",
    "Tzivya",  	"Tzofiya",  	"Tzufit",  	"Varda",
    "Vardah",  	"Vered",  	"Washti",  	"Yachna",
    "Yaen",  	"Yafa",  	"Yafe",  	"Yaffa",
    "Yaffe",  	"Yakira",  	"Yarden",  	"Yardena",
    "Yarona",  	"Yedidah",  	"Yehudit",  	"Yemima",
    "Yiskah", 	"Yocheved",  	"Yonina",  	"Yonit",
    "Yuval",  	"Zahara",  	"Zakiah",  	"Ziv",
    "Zivit",  	"Zohar"
};

QVector<QString> Peuple::NOMS_DORKADE = {
    "Aalberg", "Absalon", "Acker"
};
QVector<QString> Peuple::PRENOMS_DORKADE_FEMELLES = {
    "Angela", "Adelheid",  	"Aleit",  	"Alena",  	"Aloisia",
    "Anelie",  	"Angelika",	"Anina",  	"Anke",
    "Annegret",  	"Annelie",  	"Annelies",  	"Anneliese",
    "Anselma",  	"Antje",  	"Beate",  	"Benedikta",
    "Bettina",	"Brünhild",  	"Brunhilde",  	"Cäcilia",
    "Cäcilie",  	"Caecilia",  	"Cathrin",  	"Christa",
    "Christel",	"Constanze",	"Cordula",
    "Crescentia",  	"Dietlinde",	"Dorothea",  	"Dörthe",
    "Ebba",  	"Elfriede",  	"Elli",  	"Ermentrud",
    "Erna",	"Felizitas",  	"Fränze",  	"Franzi",
    "Franziska",  	"Frauke",  	"Frieda",  	"Friede",
    "Friederike",  	"Fritzi",  	"Gabi",  	"Gerda",
    "Gerhild",  	"Gerlinde",  	"Gertraud",  	"Gisa",
    "Gitta",  	"Gitte",  	"Gratia",  	"Gretchen",
    "Grete",  	"Gunda",  	"Gundula",  	"Hannelore",
    "Hedwig",  	"Heida",  	"Heike",  	"Heilwig",
    "Heinrike",  	"Helma",  	"Helmine",  	"Henrike",
    "Hermine",	"Herta",  	"Hertha",  	"Hilde",
    "Hildebert",	"Hildegard",  	"Hildegarde",	"Hiltraud",
    "Hiltrud",  	"Hiltrude",  	"Ilsa",  	"Ilse",
    "Imke",  	"Imma",  	"Irmentrud",  	"Irmhild",
    "Irmingard",  	"Irmtraud",  	"Irmtrud",  	"Isabell",
    "Jessika",  	"Jördis",  	"Josefine",  	"Jutta",
    "Jutte",  	"Karoline",  	"Kasimira",  	"Katarine",
    "Katharina",  	"Käthe",  	"Kathrin",  	"Katinka",
    "Katrin",	"Kerstin",  	"Kinge",  	"Konstanze",
    "Kora",  	"Kreszentia",  	"Kreszenz",  	"Kriemhild",
    "Kriemhilde",  	"Krimhilde",  	"Krista",  	"Kristiane",
    "Kunigunde",  	"Lene",  	"Leni",  	"Leonore",
    "Liane",  	"Lies",  	"Liesa",  	"Liese",
    "Liesel",  	"Lieselotte",  	"Liesl",  	"Lili",
    "Lilli",  	"Lisabeth",	"Liselotte",	"Lore",
    "Lotte",  	"Luise",  	"Luitgard",  	"Lutgard",
    "Magdalène",	"Maja",  	"Margarete",	"Margarethe",
    "Margrit",  	"Mariele",  	"Marlies",  	"Marlis",
    "Mechthild",  	"Mechtilde",  	"Meike",  	"Meta",
    "Michaela",  	"Minna",	"Mitzi",  	"Nadja",
    "Nele",  	"Oda",  	"Odilie",  	"Ortrun",
    "Ottilie",  	"Raffaela",  	"Raimunde",  	"Raphaela",
    "Rebekka",  	"Regula",  	"Reinhild",  	"Reinhilde",
    "Renate",	"Ria",  	"Rike",  	"Romy",
    "Rosemarie",  	"Roswitha",  	"Sascha",  	"Schwanhild",
    "Senta",  	"Sibylle",	"Sieghild",  	"Sieglinde",
    "Sigi",  	"Silke",  	"Sofie",  	"Sonja",
    "Sonje",  	"Stefanie",	"Steffi",	"Steffie",
    "Susann",  	"Susanne",  	"Suse",  	"Susi",
    "Svenja",  	"Swanhild",  	"Swanhilda",  	"Swanhilde",
    "Sybille",	"Tabea",  	"Tanja",  	"Théa",
    "Theda",  	"Theresia",  	"Trudi",  	"Ulrika",
    "Ulrike",  	"Ursel",  	"Uschi",  	"Ute",
    "Vreni",  	"Walburga",  	"Waltraud",  	"Wibke",
    "Zella",  	"Zenzi",  	"Zilla",  	"Ziska"
};
QVector<QString> Peuple::PRENOMS_DORKADE_MALES = {
    "Achim",  	"Adelbert",  	"Albrecht",	"Alfons",
    "Aloïs",	"Alwin",  	"Anselm",  	"Ansgar",
    "Armin",  	"Arndt",  	"Arnfried",  	"August",
    "Baldur",  	"Baptist",  	"Bartholomäus",  	"Bastian",
    "Beat",  	"Benedikt",  	"Benno",  	"Bernd",
    "Bernhard",	"Berthold",	"Bonifaz",  	"Burkhard",
    "Carl",	"Carsten",  	"Claus",	"Clemens",
    "Corbinian",	"Cord"	"Detlef",	"Didi",
    "Diederich",	"Dierk",	"Dieter",	"Dietfried",
    "Diethelm",	"Dietmar",	"Dietrich",	"Ebbe",
    "Eberhard",  	"Eckart",  	"Eckbert",  	"Eckehard",
    "Eckhard",  	"Eckhart",  	"Egon",  	"Ekkehard",
    "Ekkehardt",  	"Emil",	"Emmerich",  	"Engel",
    "Engelbert",  	"Erdmann",  	"Erhard",  	"Erich",
    "Ernest",	"Erwin",	"Eugen",	"Evert",
    "Ewald",  	"Falk",  	"Ferdi",  	"Fester",
    "Filibert",  	"Florian",	"Franz",	"Friedemann",
    "Friedhelm",  	"Friedhold",  	"Friedrich",	"Fritz",
    "Gebbert",  	"Gebhard",  	"Geert",  	"Gerd",
    "Gereon",  	"Gerfried",  	"Gerhardt",  	"Gerhold",
    "Gernot",  	"Gero",  	"Gerold",  	"Gert",
    "Gerulf",  	"Gervas",  	"Gisbert",  	"Gottfried",
    "Gotthard",  	"Gotthilf",  	"Gotthold",  	"Gottlieb",
    "Gottlob",  	"Gottschalk",  	"Gregor",  	"Günter",
    "Günther",  	"Guntram",  	"Hagen",  	"Hanke",
    "Hans",	"Hartmann",  	"Hartmut",  	"Hartwig",
    "Hartwin",  	"Heiko",  	"Heiner",  	"Heino",
    "Heinrich",  	"Heinz",	"Helfried",  	"Helmfried",
    "Helmut",  	"Helmuth",	"Henning",  	"Heribert",
    "Hermann",	"Hermenegild",  	"Hieronymus",	"Hilbert",
    "Hildebrand",  	"Hinrich",  	"Horst",	"Humbert",
    "Huppert",  	"Ignatz",  	"Immanuel",  	"Ingo",
    "Irmgard",	"Isidor",  	"Jasmin",	"Jochem",
    "Jochen",  	"Jochim",  	"Jorg",	"Josef",
    "Jürgen",  	"Jurian",  	"Justus",  	"Karlmann",
    "Karsten",  	"Kasimir",  	"Kayetan",  	"Klaas",
    "Klaus",	"Klemens",  	"Kolman",  	"Koloman",
    "Korbinian",  	"Körbl",  	"Kord",  	"Kunibert",
    "Kuno",  	"Kurt",	"Lambert",	"Lamprecht",
    "Lanzo",  	"Leberecht",  	"Lenz",  	"Leonhard",
    "Lilo",	"Lorenz",  	"Lothar",	"Ludger",
    "Ludolf",  	"Ludwig",	"Luitger",  	"Luitpold",
    "Lutz",  	"Manfred",	"Manfried",  	"Markus",
    "Marwin",  	"Marzell",  	"Mathis",	"Matthäus",
    "Mattias",  	"Max",	"Meinard",  	"Meinhard",
    "Meino",  	"Meinrad",  	"Merten",  	"Moritz",
    "Mose",  	"Nickolaus",  	"Nicolaus",	"Niklaus",
    "Nikolaus",  	"Norbert",	"Oral",  	"Orel",
    "Ortwin",  	"Othmar",  	"Otmar",  	"Ottmar",
    "Ottokar",  	"Ottomar",  	"Pankra",  	"Parsifal",
    "Quirin",  	"Raffael",  	"Raimund",	"Rainer",
    "Ralf",	"Reimund",  	"Rein",  	"Reiner",
    "Reinhard",  	"Reinhold",	"Reto",  	"Rochus",
    "Rodolf",  	"Rolf",	"Rudi",  	"Rüdiger",
    "Ruedi",  	"Rupert",	"Ruprecht",
    "Sepp",  	"Seppel",  	"Siegbert",  	"Siegfried",
    "Sieghard",  	"Siegmund",  	"Siegward",  	"Sigismund",
    "Sigmund",	"Silvester",  	"Steffen",  	"Stéphan",
    "Théodor",	"Theophil",  	"Tiedemann",  	"Tielo",
    "Till",  	"Tillo",  	"Traugott",  	"Ueli",
    "Ulrich",	"Urs",  	"Utz",  	"Uwe",
    "Veit",  	"Vester",  	"Vinzent",  	"Vinzenz",
    "Volker",	"Walther",  	"Wendel",  	"Wendelin",
    "Wenzel",  	"Wenzeslaus",  	"Werner",	"Werther",
    "Wetzel",  	"Wieland",  	"Wilfried",	"Wilhemine",
    "Willi",	"Winfried",  	"Wolf",  	"Wolfgang",
    "Wolfram",	"Wulf",  	"Yvo"
};

QVector<QString> Peuple::NOMS_ARAGON = {
    "Acosta", "Acuña", "Adalbéron",     "Abril",
    "Aguilar",
    "Aguilera",
    "Aguirre",
    "Alcaraz",
    "Almodóvar",
    "Alvar",
    "Álvarez",
    "Álvaro",
    "Arocena",
    "Arregui",
    "Arteaga",
    "Arteta",
    "Aznar",
    "Baeza",
    "Bahamonte",
    "Balaguer",
    "Bañuelos",
    "Barberá",
    "Bárcenas",
    "Bello",
    "Berdugo",
    "Berenguer",
    "Biraben",
    "Blasco",
    "Bolívar",
    "Cabestany",
    "Cadalso",
    "Campos",
    "Campuzano",
    "Canuto",
    "Caperochipi",
    "Carvallo",
    "Casal",
    "Castro",
    "Catalán",
    "Cebrián",
    "Cedeño",
    "Cervantes",
    "Cervera",
    "Cisneros",
    "Colón",
    "Cortés",
    "Domínguez",
    "Echeberría",
    "Echepare",
    "Encinas",
    "Escobar",
    "Feijoó",
    "Fernández",
    "Ferrando",
    "Fraga",
    "Francés",
    "Franco",
    "Gabaldón",
    "Gacía",
    "Gacías",
    "Gació",
    "Garcés",
    "Garsés",
    "Garzia",
    "Garzón",
    "Gaztea",
    "Pérez",
    "Gaciot",
    "Garcea",
    "Garceller",
    "Gárcez",
    "Garci",
    "García",
    "Garcías",
    "Garibay",
    "Garsea",
    "Gartzea",
    "Gartzes",
    "Gartzia",
    "Garzea",
    "Gasía",
    "Gassía",
    "Gassías",
    "Giménez",
    "Gomez",
    "Gómez",
    "Góngora",
    "González",
    "Gorrochategui",
    "Goya",
    "Gutiérrez",
    "Heredia",
    "Hernández",
    "Herrera",
    "Herrero",
    "Hortelano",
    "Ibáñez",
    "Irigoyen",
    "Jiménez",
    "Láñez",
    "Llorente",
    "López",
    "Machado",
    "Machain",
    "Machinandiarena",
    "maestre",
    "Marichalar",
    "Martínez",
    "Matilla",
    "Melo",
    "Mendoza",
    "Molina",
    "Monardes",
    "Montoya",
    "Morales",
    "Moreno",
    "Morestin",
    "Múgica",
    "Muñoz",
    "Murillo",
    "Núñez",
    "Ordoqui",
    "Ortiz",
    "Pacheco",
    "Pastor",
    "Pinilla",
    "Puértolas",
    "Quesada",
    "Quílez",
    "Ramírez",
    "Ribera",
    "Robledo",
    "Rodas",
    "Rodríguez",
    "Rumi",
    "Sanches",
    "Sánchez",
    "Sancho",
    "Santana",
    "Santín",
    "Sedeño",
    "Segura",
    "Sepúlveda",
    "Somoza",
    "Soriano",
    "Suárez",
    "Tarín",
    "Torres",
    "Trujillo",
    "Ubeda",
    "Ubieto",
    "Unamuno",
    "Urcelay",
    "Valenciano",
    "Vargas",
    "Velasco",
    "Velasques",
    "Velásquez",
    "Velázquez",
    "Vera",
    "Verdugo",
    "Vicente",
    "Vidal",
    "Villalobos",
    "Villanueva",
    "Villar",
    "Ximenes",
    "Ximénez",
    "Zamora",
    "Zapatero",
    "Zaplana"
};
QVector<QString> Peuple::PRENOMS_ARAGON_FEMELLES = {
    "Gabriella", "Adalia",	"Abi",	"Abril",	"Adamaris",
    "Adelma",	"Agostina",	"Agueda",	"Aidée",
    "Ailen",	"Alcira",	"Aldana",	"Alejandra",
    "Alfonsina",	"Almudena",	"Alondra",	"Ambar",
    "America",	"Amparo",	"Anaeli",	"Analia",
    "Analis",	"Angeles",	"Antonieta",	"Araceli",
    "Arantza",	"Aranza",	"Arcelia",	"Arellys",
    "Ariadna",	"Ariana",	"Arianne",	"Aroa",
    "Ayelen",	"Aylen",	"Azucena",	"Azul",
    "Asunción",  	"Asun",  	"Ascensión",  	"Amarilis",
    "Amaranta",  	"Adoración",  	"Aracelis",  	"Aracely",
    "Anunciación",  	"Angelita",  	"Amada",  	"Alita",
    "Adora",  	"Adelita",  	"Azeneth",  	"Amaya",
    "Amy",	"Amadéa",	"Alanis",	"Aïsha",
    "Agnès",	"Agustina",	"Andréa",	"Adelaïda",
    "Alicia",	"Alison",	"Alexa",	"Alexandra",
    "Alexia",	"Aglaé",	"Aura",	"Arantxa",
    "Ana",	"Anabel",	"Anabella",
    "Ana-Maria",	"Ana-Laura",	"Ana-Clara",	"Ana-Luisa",
    "Ambrosia",	"Ariel",	"Angalina",
    "Adela",	"Adelina",	"Aline",	"Amaranthe",
    "Ainhoa",	"Afra",	"Avelina", "Benilda",	"Betiana",	"Betina",	"Betsabe",
    "Briseyda",	"Benigna",  	"Bernardita",
    "Bethania",  	"Bienvenida",  	"Brunilda",  	"Brunella",	"Benita",	"Bertha",	"Blanca",
    "Blanca-Estèla",	"Bella",	"Beatriz",	"Begoña",
    "Brenda",	"Belen", "Candela",	"Candelaria",	"Caridad",	"Carlina",
    "Carlota",	"Catalia",	"Celene",	"Charo",
    "Chita",	"Concepcion",	"Conception",	"Conchita",
    "Cintia",	"Circe",	"Citlalli",	"Claudina",
    "Calixta",  	"Cande",  	"Candelas",  	"Carmelita",
    "Celestina",  	"Chelo",  	"Chus",  	"Concha",
    "Consuela",	"Crescencia",  	"Cruzita",  	"Custodia",
    "Célia",	"Carmina",	"Coral",	"Constanza",
    "Carolin",	"Clarisa",	"Chiara-Maria",
    "Corina",	"Cloé",	"Célina",
    "Carina",	"Catalina",	"Catherine",	"Casandra", "Dalma",	"Damaris",	"Darlyne",	"Deidamia",
    "Delicia",	"Denisse",	"Dilcia",
    "Dilean",	"Dinora",	"Dominga",	"Domitila",
    "Dina",	"Danaé",	"Désirée",	"Dana",
    "Dania",	"Dulce",	"Delta",	"Doïna",
    "Dominica",	"Dominico",	"Daina", 	"Edelmira",	"Edilma",	"Eduina",
    "Elba",	"Elcira",	"Elenor",	"Elida",
    "Elinathan",	"Eloisa",	"Elva",
    "Emilce",	"Encarnacion",	"Enriqueta",	"Ercilia",
    "Erlinda",	"Esneda",	"Etelvina",	"Evangelina",
    "Evelia",	"Elodia",  	"Emelina",  	"Emigdia",
    "Emperatriz",  	"Encarna",  	"Encarnita",  	"Eléonor",
    "Estefania",	"Emanuella",	"Elena-Ofelia",
    "Esther",	"Estèla",	"Estrella",	"Ethel",
    "Elvia",	"Erika",	"Eda",	"Enid",
    "Ernestina",	"Esperanza",	"Ermanda",	"Emilia",
    "Edna",	"Ema",    "Eve",	"Evita", "Felicidad",	"Farina",	"Felicitas",	"Felipa",
    "Felisa",	"Fiama",	"Filis",	"Fina",
    "Florentina",	"Francisca",	"Feliciana",  	"Fran",
    "Fernanda",	"Fiona",	"Florencia",	"Félicia",
    "Fidelia",	"Fidelina",	"Fidela",	"Fania", "Genovea",	"Geraldina",	"Gimena",	"Ginna",
    "Gintare",	"Glorymar",	"Goretti",	"Graciela",
    "Grecia",	"Grisel",	"Griselda",	"Guadalupe",
    "Guillermina",	"Garsea",  	"Graciana",  	"Gala",
    "Gina",	"Giulianna",	"Galia",	"Gilberta",
    "Gil",	"Giselle",	"Gisel",	"Gisela",
    "Giselda",	"Gisell",	"Gabriela",	"Grace",
    "Gracia",	"Georgina",	"Gertrudis", "Gretel",	"Gladys",	"Glenda", "Hebe",	"Herendiara",	"Herminia",
    "Higinia",	"Hilda",	"Helena",	"Hannah",	"Hortensia",	"Helga",	"Heidi",	"Hedda", "Idalia",	"Iracema",	"Irupe",	"Iselda",
    "Isolda",	"Itati",	"Izana",	"Idoya",
    "Inmaculada",  	"Isabela",  	"Ivette",  	"Iliana",
    "Isolde",	"Iona",	"Itzel",	"Inma",
    "Isabel",	"Isadora",	"Ignacia",	"Isaura",
    "Isis",	"Ina",	"Irina", "Jacinta",	"Javiera",	"Janeth",	"Jannette",
    "Jazmin",	"Jerie",	"Jimena", "Jocabed",	"Jorgelina",	"Julieta",
    "Justiniana",	"Jesenia",  	"Jessenia",  	"Jesusa",
    "Joaquina",  	"Jordana",  	"Jovita",  "Julia",	"Julieta",	"Juliana",
    "Jade",	"Josépha",	"Joséfina",	"Jane",
    "Janet",	"Jeanne",	"Joanna",	"Johanna",
    "Juanita",	"Jeanette",	"Jenna",	"Joana",
    "Juana",	"Jo-Ann",	"Jocelin",	"Jésabel", "Katja",	"Kristine",	"Karyme",	"Katsya",
    "Keisi",	"Kobra",	"Kyra",	"Kiara","Karla",	"Karina", 	"Laisha",	"Larisa",
    "Laurentina",	"Léonela",	"Libertad",	"Libia",
    "Ligia",	"Lihuen",	"Liliam",	"Lilyane",
    "Lisaida",	"Lisseth",	"Lissette",	"Lizzeth",
    "Llisaida",	"Lorelis",	"Loyda",	"Lucrecia",
    "Luisiana",	"Luisina",	"Lupina",	"Lupita",
    "Luz",	"Laurita",  	"Loida",  	"Ludmila",
    "Léticia",	"Lynda",	"Léonor",	"Laurence", "Loren",	"Lorna",	"Laureana",
    "Lida",	"Lis",	"Lola",	"Lolita",
    "Lupe",	"Leslie",	"Lucila",	"Lucina",
    "Lucinda",	"Lilia", "Lila",	"Lourdes",	"Lidia-Cira", "Maca",	"Macarena",	"Maida",	"Malenca",
    "Marcela",	"Margoth",	"Marianela",	"Mariangela",
    "Mariangeles",	"Maricel",	"Maricela",	"Marilina",
    "Marilu",	"Marlena",	"Marzela",	"Marzul",
    "Mayra",	"Merlina",	"Micaela", "Miguelina",	"Milénia",	"Millie",
    "Mireya",	"Mora",	"Morela",	"Macaria",
    "Manola",  	"Manuelita",  	"Marianita",  	"Maricruz",
    "Marisela",  	"Maristela",  	"Martirio",  	"Martita",
    "Máxima",  	"Mayte",  	"Merche",  	"Miguela",
    "Modesta",  	"Mélina",	"Mélinda",	"Mélisa",
    "Mabel",	"Magnolia",	"Marita",	"Maïtena",
    "Maria-Auxiliadora",	"Maria-Emilce",	"Maria-Socorro",	"Mariel",
    "Mariela",	"Mariella",	"Marietta",	"Marisol",	"Marissa",	"Mia",
    "Myrna",	"Maria-Eugénia",	"Maria-Del-Carmen",	"Maria-Inès",
    "Maria-Fernanda",	"Maria-José",	"Maria-Del-Jésus",	"Maria-Hélèna",
    "Maria-Eléna",	"Maïté",	"Maria-Clara",	"Maria-Paz",
    "Maria-Lourdes",	"Maritza",	"Maria-Emilia",	"Mariana",
    "Maribel",	"Maribella",	"Martha",	"Marta-Lucia",
    "Martha-Sonia",	"Marcelina",	"Marcia",	"Manel",
    "Manuela",	"Manuella",	"Madeleine",	"Madeline",
    "Maddelline",	"Madelyn",	"Magdalena",	"Malena",
    "Milagros",	"Monserrath",	"Montserrat",	"Mélanie",
    "Magali",	"Margaret",	"Margot",	"Marjorie",
    "Margarita",	"Maya", "Nicolasa",  	"Nohemi",  	"Nieve",  	"Narcisa",
    "Nayeli",	"Nelda",	"Nelida",	"Nellida",
    "Nereida",	"Nicolasia",	"Nidia",	"Nilda",
    "Niriel",	"Nube",	"Nubia", "Naomi", "Nadina", "Nuria", "Nina",	"Natacha",
    "Natasha",	"Nathalie",	"Natali",	"Noélia",	"Nieves",	"Nerea",
    "Natividad",	"Nazarena",	"Nicole", "Olalla",  	"Odalys",  	"Obdulia",	"Odalis",
    "Odili",	"Olenca",	"Onelia",	"Orfilia",
    "Orieta",	"Oliva",	"Olivera", "Perpetua",  	"Paca",  	"Pastora",  	"Pepita",
    "Pascuala",  	"Pacífica",  	"Pandora",	"Priscila",
    "Paloma",	"Paquita",	"Paz",	"Patricia",
    "Petra",	"Paula",	"Paulina",	"Piedad",
    "Pia", "Rosenda",  	"Reyes",  	"Ricarda",  	"Ruperta",
    "Rosalva",  	"Rafa",	"Rosita",	"Rebeca",
    "Reyna",	"Rudecinda",	"Roxana",	"Raquel", "Rafaëla",	"Reina",	"Romane",
    "Rosalba",	"Roselia",	"Rosella",	"Rosinda", "Sancha",  	"Sanchia",  	"Sens",  	"Sence",
    "Salud",  	"Susanita", "Socorro",
    "Stela", "Surama",	"Sahara",
    "Salena",	"Silvina",	"Siomara",	"Sylma",
    "Samanta",	"Samara",	"Sandra",	"Sasha",
    "Stella-Maris",	"Savannah",	"Sélina",	"Susana",
    "Salomé",	"Shakira",	"Saraï",
    "Selenia",	"Soledad", "Teresita",  	"Teófila",  	"Tomasa",  	"Tere",
    "Taalia",	"Taua",	"Trinidad",	"Talia",
    "Trini",	"Thaïs",	"Thelma",	"Telma", "Uma",	"Uriel", "Valencia",  	"Visitación",  	"Varinia",	"Vicenta",
    "Vasti",	"Venecia",	"Ventura",	"Verenice",
    "Violeta",	"Valeska",	"Vanina",	"Vanesa",
    "Vilma",	"Victoria",	"Verena", "Xochilt",  	"Ximena",	"Xiomara",	"Xochitl",
    "Xénia", "Yesenia",  	"Ysabel",  	"Yanet",	"Yannel",
    "Yadira",	"Yanina",	"Yazmin",	"Yaima",
    "Yamila",	"Yamile",	"Yaneth",	"Yanira",
    "Yara",	"Yareni",	"Yasna",	"Yennifer",
    "Yesmine",	"Yessena",	"Yhoalibeth",	"Yilda",
    "Yuana",	"Yolanda",	"Yasmina",	"Yasmin",
    "Yvonne", "Zarela",	"Ziva",	"Zenaïda",	"Zaïda",
    "Zulema",	"Zulma",	"Zunilda",	"Zurine",
    "Zoraïda",	"Zoila"
};
QVector<QString> Peuple::PRENOMS_ARAGON_MALES = {
    "Rodigo", 	"Adis",	"Albertino",	"Alcidès",
    "Alioth",	"Alirio",	"Alterio",	"Anyelo",
    "Arcadio",	"Arcangel",	"Arles",	"Alfie",
    "Agapito",  	"Ari",	"Aureliano",  	"Amancio",
    "Ambrosio",  	"Américo",  	"Adolfito",  	"Alejo",
    "Amado",  	"Apolinar",  	"Asdrubal",  	"Alonso",
    "Arsenio",  	"Audie",	"Anibal",	"Arnold",
    "Albano",	"Agustin", 	"Andréas",	"Andrès",
    "Alexis",	"Alejandro",	"Alex",	"Adam",
    "Adan",	"Alvaro",	"Adriel",	"Aristides",
    "Angel",	"Absalon",	"Axel",
    "Adonis",	"Abelardo", "Bélisario",	"Blumaro",	"Borris",
    "Baldomero",	"Bolívar",  	"Baudelio",
    "Bautista",	"Bartolomé",  	"Blas",	"Buenaventura",
    "Bernardo",	"Baltasar",	"Baltazar",	"Bernabe", "Clotario",	"Crissolorio",	"Curro",  	"Carlito",
    "Carlitos",  	"Chuy",  	"Chimo",  	"Chester",
    "Che",  	"Candelario",  	"Custodio",
    "Calixto",	"Chucho",  	"Cayetano",	"Clímaco",
    "Conrado",	"Cebrián",  	"Ceferino",	"Ciríaco",
    "Celestino",  	"Cecilio",  	"Casimiro",  	"Cruz",
    "Constantino",	"Cornelio",	"Carol",	"Carlos",
    "Camilo",	"Cristian",	"Cristobal",	"Christoph",
    "Cipriano",	"Cirilo",	"César", "Dago",	"Dagoberto",	"Dalmacio",	"Dalmiro",
    "Donaldo",	"Desi",	"Didacus",
    "Diogenes",	"Dimas",	"Delfin",
    "Diogène",	"Daniel",	"Damian",	"Dennis",
    "Dérek",	"Dan",	"Donovan",	"Domingo",
    "Duncan", "Edagar",	"Edelberto",	"Edin",	"Eras",	"Euclido",	"Ever",
    "Epifanio",  	"Eleuterio",  	"Eustaquio",  	"Ezequiel",
    "Edelmiro",  	"Emigdio",  	"Efrain",	"Eutimio",
    "Eutropio",  	"Eberardo",	"Espiridión", 	"Estavan",
    "Esteban",	"Ezéchiel",	"Emanuel",	"Eduardo",	"Eduard",
    "Ewen",	"Edgar",	"Eléazar",	"Elias",
    "Eli",	"Elian",	"Enrique",	"Enzo",
    "Elviro",	"Eric",	"Elmer",	"Eladio",
    "Edmundo", "Fernan",	"Facundo",	"Fantino",	"Fito",
    "Felipe",	"Florentino",  	"Fulgencio",  	"Fabricio",
    "Fermin",	"Fabian",	"Florencio",	"Félix",
    "Faustin",	"Faustino",	"Fidel",	"Francisco",
    "Faride", "Galeno",	"Genaro",	"Gerson",	"Giano",
    "Gildardo",	"Gilmer",	"Goar",	"Gaspare",	"Gasparo",	"Gervasio",
    "Godofredo",	"Graciano",	"Goyo",  	"Gabino",
    "Galo",  	"Gualterio",	"Gaston",	"German",
    "Gabriel",	"Gaspard",	"Gaspar",	"Georges",
    "Gérard",	"Gerhard",	"Geraldo",	"Gonzalo",
    "Guillermo",	"Gideon",	"Gadiel", "Honorato",	"Harlin",	"Haroldo",	"Homero",	"Honorio",	"Horaz",
    "Huberto",	"Heber",	"Horacio",	"Hiram",
    "Hernan",	"Hermenegildo",	"Herberto",  	"Heraclio",
    "Hazel",	"Herminio",	"Hector",	"Hernando",
    "Hermès",	"Hipolito",	"Héliodoro",	"Hubert",
    "Humberto",	"Hugo",	"Heriberto",	"Horace", "Iberico",	"Idelfonso",	"Iskandar",
    "Inocencio",  	"Ildefonso",  	"Isidro",	"Ismaël",	"Imanol",	"Isaï",	"Isaias",
    "Isidoro",	"Ignace",	"Ignacio",
    "Iñigo",	"Ilian",	"Israël",	"Isaac", "Jairo",	"Janoc",	"Jorvic",	"Justo",
    "Juanito",  	"Jair",	"Jenaro",	"Jafet",
    "Joaquin",	"Jimeno",  	"Jojo",	"Julio",	"Joshua",	"Josue",
    "José",	"José-Luis",	"Jeremias",	"Juan", "Juan-Cruz",	"Juan-José",	"Juan-Manuel",	"Juan-Carlos",
    "Juan-Pablo",	"Juan-Domingo",	"Jésus",	"Jasper",
    "Jorge",	"Javier",	"Jéronimo",	"Jacinto",
    "Jason",	"Justino",	"Jacob",
    "Jacques",	"Jakob",	"Jacobo", 	"Kaspar", "Lautaro",	"Leal",	"Lenin",	"Leobardo",
    "Liberato",	"Lonhard",	"Lucero",	"Lorencio",
    "Lalo",  	"Lincoln",	"Ladislao",	"Leocadio",
    "Leoncio",  	"Lope",  	"Lisandro",	"Lennard",
    "Loreto",	"Lancelot",	"Laurent", "Lazaro",	"Léonard", "Luis",	 "Lino",	"Léo",	"Léonel",	"Léonidas",
    "Léonidès",	"Luc",	"Lucas",	"Lilian",
    "Lillian",	"Lévi", "Macedonio",	"Magno",	"Malaquias",	"Marconio",
    "Marquesio",	"Mesias",	"Milciades",	"Misael",
    "Miguelito",  	"Marcelino",  	"Marcelo",	"Maximiano",
    "Maximino",  	"Moïses",	"Manolo",  	"Melchor",
    "Macario",  	"Marian",	"Marcel",	"Martin",
    "Marcos",	"Marco-Antonio",	"Marcial",	"Manuel",
    "Malcom",	"Mateo",	"Matias",	"Maximiliano",
    "Maximo",	"Michel",	"Miguel",	"Milton",
    "Melchior",	"Mauricio", "Neftali",	"Neptali",	"Néron",	"Nacho",
    "Nicanor",	"Nahum",	"Nahuel",	"Nando",
    "Nacio",  	"Natanael",  	"Nicolao",  	"Nelson", "Nataniel",	"Noël",	"Natalio",
    "Néréo",	"Napoléon",	"Nazareno",	"Nicolas",
    "Nestor", "Oderico",	"Onan",	"Orangel",	"Origenes",
    "Obed",	"Olegario",	"Ona",	"Oswaldo",
    "Octavio",	"Ovidio",	"Otto",	"Oliverio", "Pancracio",	"Patrocinio",	"Pompeyo",	"Pantaleon",
    "Pastor",  	"Pancho",	"Pepe",  	"Pepito",
    "Pánfilo",  	"Pacifico",	"Paris",	"Paco",
    "Paquito",	"Patricio",	"Pascual",	"Pablo",
    "Paulino",	"Paulo",	"Pedro", "Quique",  	"Quintin", "Radames",	"Rainiero",	"Randolfo",	"Recaredo", "Rigoberto", "Rico",
    "Raimundo",	"Raymundo",  	"Régulo",  	"Rodolfito",
    "Rosendo",  	"Rainerio",  	"Roldán",  	"Ruperto",
    "Remedios",	"Rocio",	"Robin",	"Renzo",
    "Rafaël",	"Ramiro",	"Roger",	"Rogelio", "Ramsès",	"Ricardo",	"Richard",
    "Reynaldo",	"Ramon",	"Raymond",	"Remigio",
    "René",	"Roque", "Sigfrido",	"Solimar",	"Saulo",	"Saveiro",
    "Segismundo",	"Segundo",	"Shaqueel",	"Silvino", "Santino",	"Santos",	"Sans",
    "Seve",  	"Sandalio",  	"Sofronio",  	"Sosimo",
    "Saturnino",  	"Sabas",  	"Saul", "Sandro",	"Santiago",	"Sévero",	"Silvestre",
    "Sanson",	"Salomon",	"Simon",	"Sébastian",
    "Sancho",	"Socrates",	"Salvador",	"Sol",
    "Samuel", "Transito",	"Tomeo",	"Torcuato",	"Troilo",
    "Telemaco",	"Tulio",	"Tercero",  	"Tiago",
    "Tiburcio",  	"Toño",  	"Tancredo",  	"Teódulo",
    "Tadeo",	"Téo",	"Tobias",	"Téodoro",
    "Tyrone",	"Toni",	"Tomas",	"Tirso",
    "Téobaldo",	"Telmo",	"Téofilo",	"Toribio", "Ubaldino",	"Urso",	"Uzziel",	"Ulises", "Valdo",	"Venancio",	"Venceslao",	"Velasco",
    "Valdemar",	"Victorino",  	"Vidal", "Venceslas",	"Vilmar",	"Vicente",	"Valentin", "Victor", "Wenceslao",	"Waldo", "Wilfredo", "Waldemar", "Ximeno",  	"Xaver",	"Xavier",
    "Ysmaël",	"Yamil",	"Yago",	"Yaël",
    "Yuli", "Zafiro",	"Zacarias", "Zoilo"
};

QVector<QString> Peuple::NOMS_OCCIDENTIN = {
    "d'Aiglemont", "d'Aiguemorte", "d'Aiguevive", "d'Aspremont", "de Beaulieu", "de Beaupré", "de Belleforest",
    "de Bellegarde", "de Bénévent", "de Blancmoustier", "de Boisjoli", "de Boutefeu", "de Clairefontaine",
    "de Clairval", "de Clochemerle", "de la Combe-aux-Cerfs", "de la Combe-aux-Loups", "de Courtelande",
    "de Courtepaille", "d'Engoulevent", "de Fiercastel", "de Gardefeu", "de Hauterive", "de Hauteroche",
    "de Hautfort", "de Hurlevent", "du Lac de Maisonfort", "de Mondragon", "de Montaigu", "de Montalembert",
    "de Montardent", "de Montbard", "de Montfaucon", "de Montfleury", "deMontjoye", "de Montmirail",
    "de Montorgueil", "de Morneplaine", "de Mortelande", "de Mortelune", "de Neuville", "de Noirmoustier",
    "de Sautemouton", "de Sauveterre", "de Sombretour", "de Sombreval", "de Songecreux", "de Valvert",
    "le Bel", "le Bon", "le Brave", "le Fier", "le Franc", "le Hardi", "le Jeune", "le Matois", "le Preux", "le Sagace",
    "le Sage", "le Taciturne", "Barberousse", "Brisefer", "Coeur-de-Lion", "Dent-de-Loup", "Sang-de-Boeuf", "Taillefer",
    "Tuemouches", "Langlois", "Duchesne", "Marchand", "Boulanger", "le Chauve", "Courtois", "Ageorges", "Aubernard", "Alamartine",
    "Fromentin", "Rabier", "Coulomb", "Cabrera", "Poudevigne", "Messonnier", "Métivier", "Pelletier", "Larsonneur",
    "Castagnier", "Nouet", "Lebreton", "Manceau", "Legros", "Lenain", "Sarrazin", "Chauvin", "Roux",
    "Abarnou", "Abattu", "Abbadie", "Abéjean", "Abellan", "Abeloos", "Abijou", "Abillard", "Abisseror", "Abrassart",
    "Abravanel", "Abrazard", "Abribat", "Abric", "Abrigeon", "Abriol", "Absalon", "Acharles", "Acheriteguy", "Achotte",
    "Achouline", "Adélaïde", "Adelmard"
};
QVector<QString> Peuple::PRENOMS_OCCIDENTIN_MALES = {
    "ALPHONSE", "AMEDEE", "AMINA", "ARNAUD", "ARTHUR", "AUDOIN", "BAUDOIN",
    "Aalongue", "Abbaud", "Abbon", "Abelène", "Abran", "Abzal", "Acelin", "Achaire",
    "Achard", "Acheric", "Adalard", "Adalbaud", "Adalbéron", "Adalbert", "Adalelme",
    "Adalgaire", "Adalgise", "Adalicaire", "Adalman", "Adalric", "Adebran", "Adélard",
    "Adelbert", "Adelin", "Adenet", "Adhémar", "Adier", "Adinot", "Adolbert", "Adon",
    "Adoul", "Adrier", "Adson", "Agambert", "Aganon", "Agebert", "Agelmar", "Agelric",
    "Agenulf", "Agerad", "Ageran", "Agilbert", "Agilmar", "Aglebert", "Agmer", "Agnebert", "Agrestin", "Agrève",
    "Aibert", "Aicard", "Aimbaud", "Aimin", "Aimoin", "Airard", "Airy", "Alard", "Albalde", "Albaud", "Albéron",
    "Alboin", "Albuson", "Alchaire", "Alchas", "Alcuin", "Alleaume", "Amanieu", "Amat", "Amblard", "Anaclet",
    "Ansbert", "Anselin", "Ansoald", "Archambaud", "Arembert", "Arnat", "Artaud", "Aubry", "Authaire", "Avold",
    "Ayoul", "Barnoin", "Barral", "Baudri", "Bérard", "Bérenger", "Bernon", "Bettolin", "Betton", "Brunon",
    "Burchard", "Caribert", "Centule", "Childebert", "Chilpéric", "Cillien", "Clodomir", "Clotaire", "Cloud",
    "Colomban", "Conan", "Conrad", "Cybard", "Dacien", "Dadon", "Dalmace", "Dambert", "Dioclétien", "Doat",
    "Drogon", "Durand", "Eadwin", "Ebbon", "Ebehard", "Eddo", "Edwin", "Egfroi", "Égilon", "Eilbert", "Einold",
    "Éon", "Ermenfred", "Ermengaud", "Ernée", "Ernold", "Ernoul", "Eumène", "Eunuce", "Euric", "Eustaise", "Euverte",
    "Evroult", "Fleuret", "Flocel", "Flodoard", "Flouard", "Flour", "Floxel", "Folquet", "Fortunat", "Foulque",
    "Frajou", "Frambault", "Frambourg", "Frameric", "Francaire", "Fulbert", "Gailhart", "Gaillon", "Garréjade",
    "Gaubert", "Gerbert", "Giboin", "Gildric", "Gislebert", "Godomer", "Gossuin", "Guéthenoc", "Guibin", "Guiscard",
    "Hatton", "Haynhard", "Héribert", "Herlebald", "Herlebauld", "Herlemond", "Hildebald", "Hildebrand",
    "Hilduin", "Hoel", "Honfroi", "Hugon", "Humbaud", "Isembert", "Ithier", "Jacquemin", "Jacut", "Lagier", "Lambert",
    "Lancelin", "Léothéric", "Lidoire", "Lisiard", "Lothaire", "Lubin", "Maïeul", "Malulf", "Marcuard", "Maric",
    "Materne", "Matfrid", "Matifas", "Maur", "Mauront", "Mesmin", "Milon", "Odo", "Oldaric", "Orderic", "Oricle",
    "Premon", "Rachio", "Radoald", "Radulf", "Raginard", "Raimbaut", "Raimbert", "Rainier", "Rainon", "Ramnulf",
    "Ranulfe", "Rataud", "Rodron", "Romary", "Roscelin", "Rostang", "Salvin", "Savaric", "Savary", "Sébaste",
    "Senoc", "Sicard", "Siegebert", "Sifard", "Sigebert", "Taillefer", "Taurin", "Théodebert", "Théodemar",
    "Theoderich", "Théodran", "Thérouanne", "Thiégaud", "Ursicin", "Ursion", "Vantelme", "Volusien", "Warin",
    "Wigeric", "Willibert", "Wulfoald", "Wulgrin",
    "Acelin", "Amaury", "Anselme", "Anthiaume", "Arthaud", "Aubert", "Audibert", "Aymeric", "Aymon", "Barthélémi",
    "Benoît", "Bérard", "Bernier", "Bertrand", "Bohémond", "Edmond", "Enguerrand", "Ernaut", "Eudes", "Galaad",
    "Garin", "Garnier", "Gauthier", "Gauvain", "Gibouin", "Gilemer", "Girart", "Godefroy", "Gontran",
    "Gonzagues", "Grégoire", "Guerri", "Guilhem", "Hardouin", "Herbert", "Herchambaut", "Hubert", "Hugues",
    "Huon", "Jehan", "Lancelot", "Merlin", "Perceval", "Philibert", "Raoul", "Raymond", "Renaud", "Robert",
    "Roland", "Savari", "Sigismond", "Tancrède", "Thibaut", "Tristan", "Urbain", "Ybert", "Yvain", "Abélard"
};
QVector<QString> Peuple::PRENOMS_OCCIDENTIN_FEMELLES = {
    "ADELAIDE", "AGNES", "ALIENOR", "ANASTASE", "ANASTASIE", "ASTRID", "AUDE", "AURE",
    "Aalis", "Ada", "Adalarde", "Adalasinde", "Adalburge", "Adalinde", "Adalsende", "Adalsinde", "Ade",
    "Adélaïde", "Adelberge", "Adèle", "Adelheit", "Adeline", "Adelsinde", "Adnette", "Adrehilde", "Advise", "Aélais",
    "Aelidis", "Aelis", "Aélith", "Aénor", "Agarde", "Agathe", "Agelberte", "Ageruchia", "Agnoflède", "Aiga", "Aïn",
    "Alaine", "Alaison", "Alaiseta", "Alaizie", "Alarèse", "Alayde", "Alazaïs", "Albérade", "Albereda", "Albérée",
    "Alberte", "Albine", "Alboflède", "Alchima", "Alcima", "Aldeberge", "Aléide", "Aliénor", "Aliète", "Aliote",
    "Alix", "Almodis", "Ameline", "Aneglie", "Ansgarde", "Arambour", "Aremburge", "Arlette", "Asceline",
    "Assalid", "Attala", "Audeburge", "Audefledis", "Audovère", "Aubrée", "Auge", "Austreberthe", "Azelaïs",
    "Barbe", "Balde", "Bathilde", "Bayonne", "Béatrix", "Bénigne", "Berthe", "Betton", "Boussarde", "Brunehaut",
    "Brunissende", "Carensa", "Carétène", "Clervie", "Clotsende", "Clotsinde", "Dangerosa", "Déda", "Dies",
    "Elbore", "Eliette", "Elvide", "Emillane", "Emma", "Erembourg", "Ermelne", "Ermengarde", "Ermenjart",
    "Ermentrude", "Ermesinde", "Etiennette", "Eudoxie", "Eusébie", "Fleur", "Floberte", "Flodoberte",
    "Flor", "Flore", "Foi", "Framehilde", "Franchilde", "Gabrielle", "Gausle", "Gebétrude", "Gerberge",
    "Gerberte", "Gerloc", "Gersinde", "Gillete", "Gillote", "Gisla", "Glossinde", "Gontrade", "Guen",
    "Guillemette", "Guiraude", "Hélits", "Hermine", "Hersent", "Hildegarde", "Huguette", "Hugonette",
    "Hylde", "Ide", "Inde", "Ingonde", "Jutta", "Lampagia", "Léceline", "Leudeberte", "Liutgarde", "Mahaud",
    "Mahaut", "Malorsie", "Marguerite", "Mathe", "Mathie", "Mathilde", "Mechtilde", "Mélie", "Métronie", "Mode",
    "Nantechilde", "Ode", "Odete", "Odile", "Odonette", "Opportune", "Ostrogotho", "Pétronille", "Phébalde",
    "Placidina", "Plectrude", "Poppa", "Praetoria", "Pulcelle", "Ragnachilde", "Régina", "Renaude", "Richilde",
    "Rictrude", "Rixende", "Robresse", "Rodheid", "Rosemonde", "Rothaïde", "Rotrude", "Sanche", "Sancie", "Sara",
    "Sédeleude", "Sénégonde", "Sichède", "Souveraine", "Thelchilde", "Théodechilde", "Théodora", "Théodrade",
    "Théophanie", "Waldrade", "Yolande", "Yselda", "Ysoir",
    "Aalais", "Aliénor", "Alix", "Anthéa", "Aremburge", "Artémise", "Astride", "Aude", "Barbe", "Barberine", "Béatrix",
    "Berthe", "Blanche", "Blancheflor", "Bradamante", "Brunehaut", "Cathau", "Diane", "Ermessende", "Gallendis",
    "Geneviève", "Grisélidis", "Gudule", "Guenièvre", "Hélix", "Héloïse", "Hermeline", "Hersende", "Hildegarde",
    "Iseult", "Léonor", "Letgarde", "Mahaut", "Mélissande", "Mélusine", "Milesende", "Morgane", "Ursule", "Viviane"
};

QVector<QString> Peuple::NOMS_SAABI = {
    "Aabdi", "Abdi", "Abad", "Abalhajj", "Abbou", "Abboud", "Abouab", "Aboulker", "Achiq", "Achour", "Adil"
};
QVector<QString> Peuple::PRENOMS_SAABI_MALES = {
    "Aarab", "Abbas", "Abbes", "Abd Al-Ali", "Abd Al-Hafid", "Abd Al-Hakim", "Abd Al-Halim",
    "Abd Al-Hamid", "Abd Al-Haqq", "Abd Allâh ", "Abd Ash-Shahid", "Abd Ash-Shakour ", "Abd Al-Kader", "Abd Al-Karim",
    "Abd Ul-Latif", "Abd Al-Mouqit ", "Abdel", "Abdelmajid", "Abdelmoudjib", "Abdelmouneim", "Abd Al-Wahab",
    "Abd Al-Wahid", "Abd An-Nour", "Azmar", "Bassel", "Khmaies", "Youssef", "Abd Al-Wahab", "Ali",
    "Abd Ar-Rahman", "Abd Ar-Razak", "Abd As-Samad", "Abd As-Slam", "Abd El-Jabar", "Abd El-Matine", "Abd El-Samii",
    "Abderrafi", "Abdessalam", "Abid", "Abidi", "Abû Bakr", "Achraf", "Adam", "Adib", "Adil", "Adnâan", "Afif", "Afzal",
    "Ahid", "Ahmed", "Aïssa", "Akram", "Altair", "Ali", "Amar", "Amine", "Amir", "Aniq", "Anisse", "Anwar", "Arbi", "Ari",
    "Arif", "Asmar", "Awab", "Ayham", "Aymane", "Ayoub", "Aziz", "Azz Ad-Din", "Bachir", "Badr", "Badreddine", "Baha-Eddine",
    "Bakir", "Baligh", "Bara'", "Bassem", "Bayrem", "Belkacem", "Bilal", "Borhene", "Boualem", "Boubakar", "Boubakr", "Boulbaba",
    "Boulbaba", "Brahim", "Chamseddine", "Chaabane", "Chadli", "Chahid", "Chafik", "Chakib", "Charafeddine", "Charif", "Choukri",
    "Chiheb", "Ciel", "Daoud", "Dalil", "Diyaeddine", "Dayazell", "Djamel", "Jebril", "Driss", "Dine", "Dom", "Djemaa", "Djibril",
    "Djillali", "Dib", "Djawad", "Djaouad", "Dayâan", "Daoud", "Essa",  	"Elijah",	"Elyas",	"Elyes", "Emir", "Fazl",  	"Firdaus",  	"Faysal",  	"Fadl",
    "Fakhri",  	"Fikri",  	"Faris",  	"Faruq",
    "Faraj",  	"Fihr",  	"Fayiz",  	"Faiz",
    "Fadil",  	"Farag",  	"Fareed",  	"Farooq",
    "Faizel",  	"Firdos",  	"Faruk",	"Farès",
    "Fahim",	"Fouad",	"Farouk",	"Fahmi",
    "Fouad",	"Fouad",	"Foued",	"Faudel",
    "Ferhat",	"Fahd",	"Fayçal",	"Fawzi",
    "Faouzi",	"Fadi",	"Fadel",	"Farid", "Fatih", "Ghayth",  	"Ghassan",  	"Gabir",  	"Gabr",
    "Gafar",  	"Galal",  	"Gamil",  	"Gawdat",
    "Guda",  	"Gebril",	"Ghani",	"Ghanem",
    "Ghazi",	"Ghalib"
};
QVector<QString> Peuple::PRENOMS_SAABI_FEMELLES = {
    "Atiqua", "Abir", "Abla", "Afaf", "Ahida", "Ahlam", "Aïcha", "Alia", "Alma", "Alya", "Amal", "Amina",
    "Amira", "Amna", "Aniqa", "Anissa", "Awatif", "Arbia", "Arifa", "Arij", "Asma", "Asmahane", "Assia",
    "Atiqua", "Aya", "Aziza", "Azza", "Badra", "Bahia", "Bahija", "Balkis", "Basma", "Baya", "Bayan", "Beha", "Beya",
    "Bouchra", "Bouthaïna", "Shemsa", "Camilla", "Camélia", "Célia", "Chahida", "Chahla", "Chama", "Chafika", "Chaïnez",
    "Cherine", "Chérifa", "Cirine", "Dalal", "Dalya", "Diyaa", "Dalila", "Donia", "Dounia", "Dino", "Djihane", "Djouhara",
    "Djaouida", "Dina", "Dhekra", "Emna",	"Emine",	"Esra",	"Esma", "Fairuz",  	"Fakhriyya",  	"Fariha",  	"Farrah",
    "Fathiyya",  	"Fatimah",  	"Fatin",  	"Fawziya",
    "Fawziyya",  	"Fayruz",  	"Fayza",  	"Fidda",
    "Fikriyya",  	"Fizza",  	"Feryel",	"Fathia",
    "Fouzia",	"Farah",	"Fadoua",	"Fadwa",
    "Faten",	"Fitna",	"Fadila",	"Faroudja",
    "Fahmia",	"Fella",	"Fahima",	"Fattouma",
    "Fairouz",	"Fatou",	"Fatoumata",	"Fatima",
    "Fatma",	"Fouzia",	"Fouzia",	"Fadia",
    "Farida",	"Faïza",	"Fatiha", "Galila",  	"Gamal",  	"Gamila",  	"Gathbiyya",
    "Gauhar",  	"Gawahir",  	"Gazbiyya",  	"Ghadir",
    "Ghaliya", 	"Ghufran",  	"Ghada",	"Ghizlène",
    "Ghania",	"Garmia",	"Ghalia"
};

Peuple Peuple::AleatoireCapharnaum()
{
    // construct a trivial random generator engine from a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, 100);

    int val = distribution(generator);
    QString id = "";
    if ( val < 35 )
        id = Peuple::SAABI;
    else if ( val < 75 )
        id = Peuple::SHIRADIM;
    else if ( val < 90 )
        id = Peuple::ESCARTE;
    else if (val < 99)
        id = Peuple::AGALANTHEEN;
    else {
        id = Peuple::ALFARIQN;
    }

    return Peuple(id);
}

Peuple Peuple::AleatoireEscarte()
{
    Peuple escarte(Peuple::ESCARTE);
    return escarte;
}

Peuple Peuple::AleatoireSudJazirat()
{
    // construct a trivial random generator engine from a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, 100);

    int val = distribution(generator);
    QString id = "";
    if ( val < 65 )
        id = Peuple::SAABI;
    else if ( val < 85 )
        id = Peuple::PEUPLES[1];
    else if ( val < 95 )
        id = Peuple::PEUPLES[3];
    else if (val < 99)
        id = Peuple::PEUPLES[2];
    else
        id = Peuple::ALFARIQN;

    return Peuple(id);
}

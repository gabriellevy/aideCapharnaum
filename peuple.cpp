#include "peuple.h"
#include <chrono>
#include <random>
#include "sexe.h"

Peuple::Peuple(QString id, QString sousGroupe):m_Peuple(id), m_SousGroupe(sousGroupe)
{
    if ( m_SousGroupe == "") {
        if ( id == Peuple::ESCARTE) {
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::default_random_engine generator(seed);
            std::uniform_int_distribution<int> distribution(0, 6);
            switch(distribution(generator)) {
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
    "Acosta", "Acuña", "Adalbéron"
};
QVector<QString> Peuple::PRENOMS_ARAGON_FEMELLES = {
    "Gabriella"
};
QVector<QString> Peuple::PRENOMS_ARAGON_MALES = {
    "Rodigo"
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
    "Djillali", "Dib", "Djawad", "Djaouad", "Dayâan", "Daoud"
};
QVector<QString> Peuple::PRENOMS_SAABI_FEMELLES = {
    "Atiqua", "Abir", "Abla", "Afaf", "Ahida", "Ahlam", "Aïcha", "Alia", "Alma", "Alya", "Amal", "Amina",
    "Amira", "Amna", "Aniqa", "Anissa", "Awatif", "Arbia", "Arifa", "Arij", "Asma", "Asmahane", "Assia",
    "Atiqua", "Aya", "Aziza", "Azza", "Badra", "Bahia", "Bahija", "Balkis", "Basma", "Baya", "Bayan", "Beha", "Beya",
    "Bouchra", "Bouthaïna", "Shemsa", "Camilla", "Camélia", "Célia", "Chahida", "Chahla", "Chama", "Chafika", "Chaïnez",
    "Cherine", "Chérifa", "Cirine", "Dalal", "Dalya", "Diyaa", "Dalila", "Donia", "Dounia", "Dino", "Djihane", "Djouhara",
    "Djaouida", "Dina", "Dhekra"
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

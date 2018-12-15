#include "stdafx.h"
#include "Errors.h"

// Ñåğèè îøèáîê: 0-99 - ñèñòåìíûå îøèáêè
//				100-109 - îøèáêè ïàğàìåòğîâ
//				110-119 - îøèáêà îòêğûòèÿ è ÷òåíèÿ ôàéëîâ

namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0, "[SYSTEM]Íåäîïóñòèìûé êîä îøèáêè"),
		ERROR_ENTRY_NODEF(1),
		ERROR_ENTRY_NODEF(2),ERROR_ENTRY_NODEF(3),ERROR_ENTRY_NODEF(4),ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6),ERROR_ENTRY_NODEF(7),ERROR_ENTRY_NODEF(8),ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10),ERROR_ENTRY_NODEF10(20),ERROR_ENTRY_NODEF10(30),ERROR_ENTRY_NODEF10(40),ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF10(60),ERROR_ENTRY_NODEF10(70),ERROR_ENTRY_NODEF10(80),ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "[SYSTEM]Ïàğàìåòğ -in äîëæåí áûòü çàäàí îáÿçàòåëüíî!"),
		ERROR_ENTRY_NODEF(101),ERROR_ENTRY_NODEF(102),ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104, "[SYSTEM]Ïğåâûøåíà äëèíà âõîäíîãî ïàğàìåòğà"),
		ERROR_ENTRY_NODEF(105),ERROR_ENTRY_NODEF(106),ERROR_ENTRY_NODEF(107),
		ERROR_ENTRY_NODEF(108),ERROR_ENTRY_NODEF(109),

		ERROR_ENTRY(110, "[SYSTEM]Îøèáêà ïğè îòêğûòèè ôàéëà ñ èñõîäíûì êîäîì(-in)"),
		ERROR_ENTRY(111, "[SYSTEM]Íåäîïóñòèìûé ñèìâîë â èñõîäíîì ôàéëå(-in)"),
		ERROR_ENTRY(112, "[SYSTEM]Îøèáêà ïğè ñîçäàíèè ôàéëà ïğîòîêîëà(-log)"),
		ERROR_ENTRY(113, "[SYN]Îòñòóòñòâóşò çàêğûâàşùèå êàâû÷êè"),
		ERROR_ENTRY(114,"[LEX]Ñëèøêîì äëèííûé ñòğîêîâûé ëèòåğàë"),ERROR_ENTRY_NODEF(115),
		ERROR_ENTRY(115,"[SYSTEM]Ñëèøêîì áîëüøîé òåêñò èñõîäíîãî êîäà"),
		ERROR_ENTRY_NODEF(117),ERROR_ENTRY_NODEF(118),ERROR_ENTRY_NODEF(119),
		ERROR_ENTRY(120, "[LEX]Ïğåâûøåíà ìàêñèìàëüíàÿ äëèíà èäåíòèôèêàòîğà (>10). Óñå÷åíèå äî 10"),
		ERROR_ENTRY(121,"[LEX]Äóáëèğîâàíèå èìåíè ôóíêöèè"),
		ERROR_ENTRY(122,"[LEX]Äóáëèğîâàíèå èìåíè èäåíòèôèêàòîğà èëè îòñóòñòâèå îáëàñòè âèäèìîñòè"),
		ERROR_ENTRY(123,"[LEX]Íåèçâåñòíàÿ ëåêñåìà"),
		ERROR_ENTRY(124,"[LEX]Íåèçâåñòíûé èäåíòèôèêàòîğ"),
		ERROR_ENTRY(125,"[SEM]Îòñóòñòâóåò òî÷êà âõîäà main"),
		ERROR_ENTRY(126,"[SEM]Äóáëèğîâàíèå òî÷êè âõîäà main"),
		ERROR_ENTRY_NODEF(127),
		ERROR_ENTRY_NODEF(128),
		ERROR_ENTRY_NODEF(129),
		ERROR_ENTRY_NODEF10(130),ERROR_ENTRY_NODEF10(140),ERROR_ENTRY_NODEF10(150),ERROR_ENTRY_NODEF10(160),
		ERROR_ENTRY_NODEF10(170),ERROR_ENTRY_NODEF10(180),ERROR_ENTRY_NODEF10(190),

		ERROR_ENTRY(200, "[SYN]Íåâåğíàÿ ñòğóêòóğà ïğîãğàììû"), //áëîê îøèáîê ñèíòàêñè÷åñêîãî àíàëèçàòîğà
		ERROR_ENTRY(201, "[SYN]Îøèáî÷íûé îïåğàòîğ"),
		ERROR_ENTRY(202, "[SYN]Îøèáêà â âûğàæåíèè"),
		ERROR_ENTRY(203, "[SYN]Îøèáêà â ğàññòàíîâêå çíàêîâ èëè ñêîáîê"),
		ERROR_ENTRY(204, "[SYN]Îøèáêà â ôîğìàëüíûõ ïàğàìåòğàõ"),
		ERROR_ENTRY(205, "[SYN]Îøèáêà â ïàğàìåòğàõ âûçûâàåìîé ôóíêöèè"),
		ERROR_ENTRY_NODEF(206),
		ERROR_ENTRY_NODEF(207), ERROR_ENTRY_NODEF(208), ERROR_ENTRY_NODEF(209),
		ERROR_ENTRY_NODEF10(210), ERROR_ENTRY_NODEF10(220), ERROR_ENTRY_NODEF10(230), ERROR_ENTRY_NODEF10(240), ERROR_ENTRY_NODEF10(250),
		ERROR_ENTRY_NODEF10(260), ERROR_ENTRY_NODEF10(270), ERROR_ENTRY_NODEF10(280), ERROR_ENTRY_NODEF10(290),

		//ñåìàíòè÷åñêèé àíàëèç
		ERROR_ENTRY(300, "[SEM]Íåñîâïàäåíèå òèïîâ ïàğàìåòğîâ ôóíêöèè"),
		ERROR_ENTRY(301,"[SEM]Íåñîâïàäåíèå êîëè÷åñòâà ïàğàìåòğîâ ôóíêöèè"),
		ERROR_ENTRY(302,"[SEM]Ïğèñâîåíèå àğãóìåíòó íå ñîîòâåòñòâóşùèé òèï"),
		ERROR_ENTRY(303,"[SEM]Íåäîïóñòèìûå îïåğàöèè ñî ñòğîêàìè"),ERROR_ENTRY(304,"[SEM]Îïåğàöèÿ íàä ğàçíûìè òèïàìè"),
		ERROR_ENTRY(305,"[SEM]Ôóíêöèÿ âîçâğàùàåò íåâåğíûé òèï"),ERROR_ENTRY(306,"[SEM]Âûçîâ íå ñóùåñòâóşùåé ôóíêöèè"),
		ERROR_ENTRY(307,"[SEM]×èñëî âûõîäèò çà ãğàíèöû äîïóñòèìîãî"),
		ERROR_ENTRY(308,"[SEM]Íåëüçÿ èçìåíÿòü ñòğîêîâûå ïàğàìåòğû ôóíêöèè"),ERROR_ENTRY_NODEF(309),ERROR_ENTRY_NODEF10(310),
		ERROR_ENTRY_NODEF10(320), ERROR_ENTRY_NODEF10(330), ERROR_ENTRY_NODEF10(340), ERROR_ENTRY_NODEF10(350),
		ERROR_ENTRY_NODEF10(360), ERROR_ENTRY_NODEF10(370), ERROR_ENTRY_NODEF10(380), ERROR_ENTRY_NODEF10(390),

		//ãåíåğàöèÿ
		ERROR_ENTRY_NODEF100(400),ERROR_ENTRY_NODEF100(500),ERROR_ENTRY_NODEF100(600),
		ERROR_ENTRY_NODEF100(700),ERROR_ENTRY_NODEF100(800),ERROR_ENTRY_NODEF100(900)
	};

	ERROR geterror(int id)
	{
		if (id > 0 && id < ERROR_MAX_ENTRY)
			return(errors[id]);
		else
			return(errors[0]);
	}
	ERROR geterrorin(int id, int line = -1, int col = -1)
	{
		if (id > 0 && id < ERROR_MAX_ENTRY)
		{
			errors[id].inext.col = col;
			errors[id].inext.line = line;
			return(errors[id]);
		}
		else
		{
			return(errors[0]);
		}
	}
}
.set LOCALID_FURZ, 1

MeteorFalls_FurzsCave_MapScripts::
	.byte 0

MeteorFalls_FurzsCave_EventScript_Furz::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_FURZ, MeteorFalls_FurzsCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_FURZ, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FURZ, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_FURZ, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_FurzsCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_FURZ, MeteorFalls_FurzsCave_Text_FurzDefeat
	msgbox MeteorFalls_FurzsCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_FURZ
	release
	end

MeteorFalls_FurzsCave_EventScript_Defeated::
	applymovement LOCALID_FURZ, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_FurzsCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_FurzsCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "Penner: Shit, wow, {PLAYER}{KUN}.\n"
	.string "I am amazed you knew where to find me.\p"
	.string "Do you, uh…maybe think of me as\n"
	.string "just a rock maniac?\p"
	.string "No, that can't be right.\p"
	.string "We battled alongside each other at\n"
	.string "the SOOTOPOLIS SPACE CENTER.\p"
	.string "You should have a very good idea\n"
	.string "about how good I am.\p"
	.string "Okay, {PLAYER}{KUN}, if you're going to mount\n"
	.string "a serious challenge, expect the worst!$"

MeteorFalls_FurzsCave_Text_FurzDefeat:
	.string "You…\n"
	.string "I had no idea you'd become so strong…$"

MeteorFalls_FurzsCave_Text_MyPredictionCameTrue:
	.string "Penner: Come to think of it, ever since\n"
	.string "our paths first crossed in GRANITE\l"
	.string "CAVE in DEWFORD, I had this feeling.\p"
	.string "I thought that you would eventually\n"
	.string "become the CHAMPION.\p"
	.string "My predictions usually come true.\p"
	.string "Und where will you go from here?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, even I couldn't tell you that.$"

.set LOCALID_WALDAS_DAD, 6

RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Ah shiiiit dude,\l"
	.string "es isch so hard every day…\p"
	.string "What's hard?\n"
	.string "You need to ask?\p"
	.string "It's trying to figure out what to\n"
	.string "make for meals every day.\p"
	.string "It really isn't easy coming up with\n"
	.string "meals every day.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Ah shiiiit dude,\l"
	.string "hello!\n"
	.string "Welcome to the PEPPER household.\p"
	.string "I have a question for you.\n"
	.string "Have you ever baby-sat?\p"
	.string "You see, I am a new father, so raising\n"
	.string "a child isch all new to me.\p"
	.string "Und I have a problem. My daughter\n"
	.string "WALDA doesn't laugh enough.\p"
	.string "I think she'd laugh for me if I told\n"
	.string "her something funny.\p"
	.string "Do you know of a funny word or\n"
	.string "phrase you can tell me?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "I've been saying “{STR_VAR_1}”\n"
	.string "to amuse her lately.\p"
	.string "Do you know of a better word or\n"
	.string "a phrase that might work?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Ah shiiiit dude,\l"
	.string "that's wonderful.\n"
	.string "So, let's hear it, your suggestion.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Ah shiiiit dude,\l"
	.string "isch that right?\p"
	.string "Ahh, Futz und Tripper...\l"
	.string "if you come up with a good\n"
	.string "suggestion, I am all ears.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Ah, I see.\n"
	.string "Ahh, Futz und Tripper...\l"
	.string "let's give it a try, shall we?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Ah shiiiit dude,\l"
	.string "yes! She's laughing!\n"
	.string "Ah shiiiit dude,\l"
	.string "I am as delighted as she!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Ah, I see.\n"
	.string "Ahh, Futz und Tripper...\l"
	.string "let's give it a try, shall we?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… She's not smiling at all.\n"
	.string "Maybe WALDA isch one serious child…$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Ah shiiiit dude,\l"
	.string "so you don't know any good words.\n"
	.string "I'd better think for myself, then.\p"
	.string "Hmm…\n"
	.string "How about “{STR_VAR_1}”?\l"
	.string "Let's see if that will work.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… She's not smiling at all.\n"
	.string "Maybe WALDA isch one serious child…$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Ah shiiiit dude,\l"
	.string "so you don't know any good words.\n"
	.string "I guess I'll try to amuse her with\l"
	.string "the saying I used before.\p"
	.string "Anyways, if you have a good suggestion,\n"
	.string "don't hesitate in telling me, oké?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Thank you!\p"
	.string "Shiit to you, my darling WALDA\n"
	.string "laughed for me!\p"
	.string "Actually, I may not look all that\n"
	.string "special, but I am one of DEVON\l"
	.string "CORPORATION's top researchers.\p"
	.string "So, how about I do something in return\n"
	.string "for you?\p"
	.string "I know, I'll add some new wallpaper\n"
	.string "patterns for the BOXES in the MAC\l"
	.string "Pimmel Storage System.\p"
	.string "In the wallpaper pattern menu,\n"
	.string "select “FRIENDS.”\p"
	.string "Dä will give you access to the new\n"
	.string "wallpaper patterns.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "It's a Pimmel plush DOLL!$"


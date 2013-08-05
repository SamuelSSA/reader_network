
#include "includes.h"

char *ast_get_SACSIC(unsigned char *sac, unsigned char *sic, int action) {
char *tmp;

    if ( (action == GET_SAC_SHORT) || (action == GET_SIC_SHORT) ) {
	tmp = (char *) mem_alloc(TEXT_LENGTH_SHORT);
	memset(tmp, 0x0, TEXT_LENGTH_SHORT);
    } else {
	tmp = (char *) mem_alloc(TEXT_LENGTH_LONG);
	memset(tmp, 0x0, TEXT_LENGTH_LONG);
    }

    switch(sac[0]) {
	case 0x00: { if (action == GET_SAC_SHORT) {
			strncpy(tmp, "", TEXT_LENGTH_SHORT);
		     } else if (action == GET_SAC_LONG) {
		    	strncpy(tmp, "", TEXT_LENGTH_LONG);
		     } else if (action == GET_SIC_SHORT) {
		        switch (sic[0]) {
			    case 1: { strncpy(tmp, "SMR-TFN", TEXT_LENGTH_SHORT); break; }
			    case 2: { strncpy(tmp, "SMR-PMA", TEXT_LENGTH_SHORT); break; }
			    case 3: { strncpy(tmp, "SMR-BTS", TEXT_LENGTH_SHORT); break; }
			    case 4: { strncpy(tmp, "SMR-BTN", TEXT_LENGTH_SHORT); break; }
			    case 5: { strncpy(tmp, "SMR-AST", TEXT_LENGTH_SHORT); break; }
			    case 6: { strncpy(tmp, "SMR-STG", TEXT_LENGTH_SHORT); break; }
			    case 101: { strncpy(tmp, "SMMS-TFN", TEXT_LENGTH_SHORT); break; }
			    case 102: { strncpy(tmp, "SMMS-PMA", TEXT_LENGTH_SHORT); break; }
			    case 104: { strncpy(tmp, "SMMS-BAR", TEXT_LENGTH_SHORT); break; }
			    case 105: { strncpy(tmp, "SMMS-AST", TEXT_LENGTH_SHORT); break; }
			    case 106: { strncpy(tmp, "SMMS-STG", TEXT_LENGTH_SHORT); break; }
			    default: sprintf(tmp, "%03d", sic[0]);
		        }
		     } else if (action == GET_SIC_LONG) {
		        switch (sic[0]) {
			    case 1: { strncpy(tmp, "SMR-Tene.. N", TEXT_LENGTH_LONG); break; }
			    case 2: { strncpy(tmp, "SMR-Palma..", TEXT_LENGTH_LONG); break; }
			    case 3: { strncpy(tmp, "SMR-Baraj S", TEXT_LENGTH_LONG); break; }
			    case 4: { strncpy(tmp, "SMR-Baraj N", TEXT_LENGTH_LONG); break; }
			    case 5: { strncpy(tmp, "SMR-Astur..", TEXT_LENGTH_LONG); break; }
			    case 6: { strncpy(tmp,   "SMR-Santi..", TEXT_LENGTH_LONG); break; }
			    case 101: { strncpy(tmp, "SMMS-Tene..N", TEXT_LENGTH_LONG); break; }
			    case 102: { strncpy(tmp, "SMMS-Palma..", TEXT_LENGTH_LONG); break; }
			    case 104: { strncpy(tmp, "SMMS-Baraj..", TEXT_LENGTH_LONG); break; }
			    case 105: { strncpy(tmp, "SMMS-Astur..", TEXT_LENGTH_LONG); break; }
			    case 106: { strncpy(tmp, "SMMS-Santi..", TEXT_LENGTH_LONG); break; }
			    default: sprintf(tmp, "%03d", sic[0]);
		        }
		     }
		     break;
	}
	case 0x08: { if (action == GET_SAC_SHORT) {
			strncpy(tmp, "FRA", TEXT_LENGTH_SHORT);
		     } else if (action == GET_SAC_LONG) {
		    	strncpy(tmp, "Francia", TEXT_LENGTH_LONG);
		     } else if (action == GET_SIC_SHORT) {
		        switch (sic[0]) {
		    	    case 3:  { strncpy(tmp, "AUC", TEXT_LENGTH_SHORT); break; }
			    case 23: { strncpy(tmp, "MON", TEXT_LENGTH_SHORT); break; }
			    case 24: { strncpy(tmp, "BIA", TEXT_LENGTH_SHORT); break; }
		        }
		     } else if (action == GET_SIC_LONG) {
		        switch (sic[0]) {
			    case 3:  { strncpy(tmp, "Auch Lias", TEXT_LENGTH_LONG); break; }
			    case 23: { strncpy(tmp, "Montpellier", TEXT_LENGTH_LONG); break; }
			    case 24: { strncpy(tmp, "Biarritz", TEXT_LENGTH_LONG); break; }
		        }
		     }
		     break;
	}
	case 0x68: { if (action == GET_SAC_SHORT) {
			strncpy(tmp, "POR", TEXT_LENGTH_SHORT);
		     } else if (action == GET_SAC_LONG) {
		    	strncpy(tmp, "Portugal", TEXT_LENGTH_LONG);
		     } else if (action == GET_SIC_SHORT) {
		        switch (sic[0]) {
		    	    case 1: { strncpy(tmp, "MTJ", TEXT_LENGTH_SHORT); break; }
			    case 2: { strncpy(tmp, "002", TEXT_LENGTH_SHORT); break; }
			    case 3: { strncpy(tmp, "FOI", TEXT_LENGTH_SHORT); break; }
			    case 4: { strncpy(tmp, "PTS", TEXT_LENGTH_SHORT); break; }
		        }
		     } else if (action == GET_SIC_LONG) {
		        switch (sic[0]) {
			    case 1: { strncpy(tmp, "Montejunto", TEXT_LENGTH_LONG); break; }
			    case 2: { strncpy(tmp, "Unknown02", TEXT_LENGTH_LONG); break; }
			    case 3: { strncpy(tmp, "Foia", TEXT_LENGTH_LONG); break; }
			    case 4: { strncpy(tmp, "Porto Santo", TEXT_LENGTH_LONG); break; }
		        }
		     }
		     break;
	}
	case 0x14: { 
		     if (action == GET_SAC_SHORT) {
			strncpy(tmp, "ESP", TEXT_LENGTH_SHORT);
		     } else if (action == GET_SAC_LONG) {
		    	strncpy(tmp, "España", TEXT_LENGTH_LONG);
		     } else if (action == GET_SIC_SHORT) {
		        switch (sic[0]) {
			    case 1:  { strncpy(tmp, "PA1", TEXT_LENGTH_SHORT); break; }
			    case 2:  { strncpy(tmp, "PA2", TEXT_LENGTH_SHORT); break; }
			    case 3:  { strncpy(tmp, "SAN", TEXT_LENGTH_SHORT); break; }
			    case 4:  { strncpy(tmp, "ALC", TEXT_LENGTH_SHORT); break; }
			    case 5:  { strncpy(tmp, "CAN", TEXT_LENGTH_SHORT); break; }
			    case 6:  { strncpy(tmp, "ESP", TEXT_LENGTH_SHORT); break; }
			    case 7:  { strncpy(tmp, "SOL", TEXT_LENGTH_SHORT); break; }
			    case 8:  { strncpy(tmp, "VAL", TEXT_LENGTH_SHORT); break; }
			    case 9:  { strncpy(tmp, "VLL", TEXT_LENGTH_SHORT); break; }
			    case 10: { strncpy(tmp, "ASP", TEXT_LENGTH_SHORT); break; }
			    case 11: { strncpy(tmp, "MON", TEXT_LENGTH_SHORT); break; }
			    case 50: { strncpy(tmp, "CON", TEXT_LENGTH_SHORT); break; }
			    case 51: { strncpy(tmp, "INO", TEXT_LENGTH_SHORT); break; }
			    case 52: { strncpy(tmp, "AIT", TEXT_LENGTH_SHORT); break; }
			    case 53: { strncpy(tmp, "MOT", TEXT_LENGTH_SHORT); break; }
			    case 54: { strncpy(tmp, "VIL", TEXT_LENGTH_SHORT); break; }
			    case 55: { strncpy(tmp, "PZO", TEXT_LENGTH_SHORT); break; }
			    case 56: { strncpy(tmp, "TOR", TEXT_LENGTH_SHORT); break; }
			    case 57: { strncpy(tmp, "PCH", TEXT_LENGTH_SHORT); break; }
			    case 58: { strncpy(tmp, "SES", TEXT_LENGTH_SHORT); break; }
			    case 59: { strncpy(tmp, "GAZ", TEXT_LENGTH_SHORT); break; }
			    case 60: { strncpy(tmp, "ROS", TEXT_LENGTH_SHORT); break; }
			    case 61: { strncpy(tmp, "SOL", TEXT_LENGTH_SHORT); break; }
			    case 62: { strncpy(tmp, "BAR", TEXT_LENGTH_SHORT); break; }
			    case 63: { strncpy(tmp, "RES", TEXT_LENGTH_SHORT); break; }
			    case 64: { strncpy(tmp, "RIA", TEXT_LENGTH_SHORT); break; }
			    case 65: { strncpy(tmp, "MAL", TEXT_LENGTH_SHORT); break; }
			    case 66: { strncpy(tmp, "SEV", TEXT_LENGTH_SHORT); break; }
			    case 67: { strncpy(tmp, "ELJ", TEXT_LENGTH_SHORT); break; }
			    case 68: { strncpy(tmp, "ERI", TEXT_LENGTH_SHORT); break; }
			    case 69: { strncpy(tmp, "MA2", TEXT_LENGTH_SHORT); break; }
			    case 129:{ strncpy(tmp, "BNC", TEXT_LENGTH_SHORT); break; } 
			    case 130:{ strncpy(tmp, "VNC", TEXT_LENGTH_SHORT); break; } 
			    case 131:{ strncpy(tmp, "PLM", TEXT_LENGTH_SHORT); break; }
			    case 132:{ strncpy(tmp, "BEG", TEXT_LENGTH_SHORT); break; }
			    case 133:{ strncpy(tmp, "RAN", TEXT_LENGTH_SHORT); break; }
			    case 134:{ strncpy(tmp, "ALC", TEXT_LENGTH_SHORT); break; }
			    case 135:{ strncpy(tmp, "TUR", TEXT_LENGTH_SHORT); break; }
			    case 193:{ strncpy(tmp, "GNC", TEXT_LENGTH_SHORT); break; }
			    case 194:{ strncpy(tmp, "TNS", TEXT_LENGTH_SHORT); break; }
			    case 195:{ strncpy(tmp, "PDC", TEXT_LENGTH_SHORT); break; }
			    case 196:{ strncpy(tmp, "LPM", TEXT_LENGTH_SHORT); break; }
			    case 197:{ strncpy(tmp, "TBN", TEXT_LENGTH_SHORT); break; }
			    case 201:{ strncpy(tmp, "AST", TEXT_LENGTH_SHORT); break; }
			    default: sprintf(tmp, "%03d", sic[0]);
			}
		    } else if (action == GET_SIC_LONG) {
		        switch (sic[0]) {
			    case 1:  { strncpy(tmp, "Para... I", TEXT_LENGTH_LONG); break; }
			    case 2:  { strncpy(tmp, "Par... II", TEXT_LENGTH_LONG); break; }
			    case 3:  { strncpy(tmp, "Santiago", TEXT_LENGTH_LONG); break; }
			    case 4:  { strncpy(tmp, "Alcolea", TEXT_LENGTH_LONG); break; }
			    case 5:  { strncpy(tmp, "Cancho...", TEXT_LENGTH_LONG); break; }
			    case 6:  { strncpy(tmp, "Espiñe...", TEXT_LENGTH_LONG); break; }
			    case 7:  { strncpy(tmp, "Solorzano", TEXT_LENGTH_LONG); break; }
			    case 8:  { strncpy(tmp, "Valdes...", TEXT_LENGTH_LONG); break; }
			    case 9:  { strncpy(tmp, "Vallad...", TEXT_LENGTH_LONG); break; }
			    case 10: { strncpy(tmp, "As Pontes", TEXT_LENGTH_LONG); break; }
			    case 11: { strncpy(tmp, "Monflo...", TEXT_LENGTH_LONG); break; }
			    case 50: { strncpy(tmp, "Constan..", TEXT_LENGTH_LONG); break; }
			    case 51: { strncpy(tmp, "Inoges", TEXT_LENGTH_LONG); break; }
			    case 52: { strncpy(tmp, "Aitana", TEXT_LENGTH_LONG); break; }
			    case 53: { strncpy(tmp, "Motril", TEXT_LENGTH_LONG); break; }
			    case 54: { strncpy(tmp, "Villato..", TEXT_LENGTH_LONG); break; }
			    case 55: { strncpy(tmp, "Pozo Ni..", TEXT_LENGTH_LONG); break; }
			    case 56: { strncpy(tmp, "Torrejon", TEXT_LENGTH_LONG); break; }
			    case 57: { strncpy(tmp, "Peñas C..", TEXT_LENGTH_LONG); break; }
			    case 58: { strncpy(tmp, "Sierra E.", TEXT_LENGTH_LONG); break; }
			    case 59: { strncpy(tmp, "Alcala G.", TEXT_LENGTH_LONG); break; }
			    case 60: { strncpy(tmp, "Rosas", TEXT_LENGTH_LONG); break; }
			    case 61: { strncpy(tmp, "Soller", TEXT_LENGTH_LONG); break; }
			    case 62: { strncpy(tmp, "Barbanza", TEXT_LENGTH_LONG); break; }
			    case 63: { strncpy(tmp, "Resvala..", TEXT_LENGTH_LONG); break; }
			    case 64: { strncpy(tmp, "Riaza", TEXT_LENGTH_LONG); break; }
			    case 65: { strncpy(tmp, "Málaga", TEXT_LENGTH_LONG); break; }
			    case 66: { strncpy(tmp, "Sevilla", TEXT_LENGTH_LONG); break; }
			    case 67: { strncpy(tmp, "El Judio", TEXT_LENGTH_LONG); break; }
			    case 68: { strncpy(tmp, "Erillas", TEXT_LENGTH_LONG); break; }
			    case 69: { strncpy(tmp, "Malaga 2", TEXT_LENGTH_LONG); break; }
			    case 129:{ strncpy(tmp, "Barcelona", TEXT_LENGTH_LONG); break; } 
			    case 130:{ strncpy(tmp, "Valencia", TEXT_LENGTH_LONG); break; } 
			    case 131:{ strncpy(tmp, "Palma d..", TEXT_LENGTH_LONG); break; }
			    case 132:{ strncpy(tmp, "Begas", TEXT_LENGTH_LONG); break; }
			    case 133:{ strncpy(tmp, "Randa", TEXT_LENGTH_LONG); break; }
			    case 134:{ strncpy(tmp, "Alcolea", TEXT_LENGTH_LONG); break; }
			    case 135:{ strncpy(tmp, "Turrillas", TEXT_LENGTH_LONG); break; }
			    case 193:{ strncpy(tmp, "Gran Ca..", TEXT_LENGTH_LONG); break; }
			    case 194:{ strncpy(tmp, "Teneri...", TEXT_LENGTH_LONG); break; }
			    case 195:{ strncpy(tmp, "Penas d..", TEXT_LENGTH_LONG); break; }
			    case 196:{ strncpy(tmp, "La Palma", TEXT_LENGTH_LONG); break; }
			    case 201:{ strncpy(tmp, "Asturias", TEXT_LENGTH_LONG); break; }
			    default: sprintf(tmp, "%03d", sic[0]);
		        }
		    }
		    break;
	}
	default: {
	    //char t[10];
	    //memset(t,0x0, 10);
	    //sprintf(t, "%03d",  sic[0]);
	    
	    if (action == GET_SAC_SHORT) {
		snprintf(tmp, TEXT_LENGTH_SHORT, "%03d", sac[0]);
	    } else if (action == GET_SAC_LONG) {
	    	snprintf(tmp, TEXT_LENGTH_LONG, "Uknown(%03d)", sac[0]);
	    } else if (action == GET_SIC_SHORT) {
		snprintf(tmp, TEXT_LENGTH_SHORT, "%03d", sic[0]);
	    } else if (action == GET_SIC_LONG) {
	    	snprintf(tmp, TEXT_LENGTH_LONG, "Uknown(%03d)", sic[0]);
	    }
	    /*
	    if ( (action == GET_SIC_SHORT) || (action == GET_SAC_SHORT) ) {
//		    strncpy(tmp, "UNK", TEXT_LENGTH_SHORT);
		    strncpy(tmp, t, TEXT_LENGTH_SHORT);
	    } else {
//		    strncpy(tmp, "unknown", TEXT_LENGTH_LONG);
		    strncpy(tmp, t, TEXT_LENGTH_SHORT);
	    }
	    */
	}
    }	

    return tmp;
}

/*
    switch(sic[0]) {
        case 1: { strcpy(tmp, "Paracuellos I"); break; }
	case 2: { strcpy(tmp, "Paracuellos II"); break; }
	case 4: { strcpy(tmp, "Alcolea"); break; }
	case 7: { strcpy(tmp, "Sol�rzano"); break; }
	case 9: { strcpy(tmp, "Valladolid"); break; }
	case 10: { strcpy(tmp, "As Pontes"); break; }
	case 11: { strcpy(tmp, "Monflorite"); break; }
	case 130: { strcpy(tmp, "Valencia"); break; }
	
	default:   { strcpy(tmp, "unknown"); break; }
    }

    return tmp;
}
*/
/*
 *                             BOTS
*/
#include <iostream>
#include <curl/curl.h>

void enviarMensaje(const std::string& token, const std::string& chat_id, const std::string& mensaje){
	    //URL de la API de Telegram
	    //std::cout<<"https://api.telegram.org/bot"+ token + "/sendMessage?chat_id=" + chat_id + "&text=" + mensaje;
		std::string url = "https://api.telegram.org/bot"+ token + "/sendMessage?chat_id=" + chat_id + "&text=" + mensaje;
		//std::string url = "https://api.telegram.org/bot7972870040:AAGi8Ksd4sLmdIfSYGLgy7DM_NmTZtZ3ews/sendMessage?chat_id=6002292007&text=HOOOLA";
		//Inicializar CURL
		CURL *curl = curl_easy_init();
		if(curl){
				//configuramos la URL
				curl_easy_setopt(curl,CURLOPT_URL,url.c_str());
				//Ejecutar la peticion
				CURLcode res = curl_easy_perform(curl);
				if(res != CURLE_OK){
					std::cerr<<"Error en CURL: "<<curl_easy_strerror(res)<<std::endl;
					}
				curl_easy_cleanup(curl);
			}
	}

int main(){
    std::string token = "7972870040:AAGi8Ksd4sLmdIfSYGLgy7DM_NmTZtZ3ews";
    std::string chat_id = "6002292007";
    std::string mensaje = "ALERTA";
    enviarMensaje(token,chat_id,mensaje);
	return 0;
}

#include <bits/stdc++.h>
#include "openssl/include/openssl/sha.h"
using namespace std;

string sha256(const string str) {
    char buf[2];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::string NewString = "";
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(buf,"%02x",hash[i]);
        NewString = NewString + buf;
    }
        return NewString;
}

int main() {
    string auth{};
    string inputkey{};
    string key{};
    ifstream myFile;
    myFile.open("authkey.txt");
    if(!file) {
        cout << "您尚未生成驗證碼，程式將自動關閉" << endl;
        exit()
    }
    getline(myFile, key));
    myFile.close();

    cout << "請輸入雙重驗證密碼" << endl;
    cin >> inputkey;
    if(sha256(inputkey) == key) {
        cout << "pass" << endl;
        cout << "登入視同您同意隱私權條款，請按下一步以顯示隱私權條款" << endl;
        cout " 	
Termos e condições de uso


Wikimedia-logo.svg
Este é um sumário legível dos termos de uso.
Aviso: Este sumário não é parte dos termos de uso e não é um documento legal. É simplesmente uma referência acessível para compreender as condições de uso em sua totalidade. Pense nisto como uma interface amigável da linguagem legal dos nossos termos de uso.

Parte de nossa missão é:

    Capacitar e atrair pessoas em todo mundo a compilar e desenvolver conteúdo educacional e publicá-lo sob uma licença livre ou dedicá-lo ao domínio público.
    Disseminar esse conteúdo de maneira global e efetiva, sem custos.


Você é livre para:

    Ler e imprimir gratuitamente nossos artigos e outras mídias.
    Compartilhar e reutilizar nossos artigos e outras mídias sob licenças livres e abertas.
    Contribuir e editar em nossos projetos.


Sob as seguintes condições:

    Responsabilidade — Você é responsável por suas edições (visto que nós somente hospedamos o seu conteúdo).
    Civilizado — Você será educado e cortês, e não molestará os outros usuários.
    Comportamento legal — Você não infringirá as leis dos direitos autorais nem qualquer outra lei.
    Sem danos — Você não danificará a nossa infraestrutura tecnológica.
    Temos e condições de uso e políticas — Você aceita os seguintes termos e condições de uso, e as políticas aplicáveis das comunidades, quando você visitar nossos sites e nossas comunidades.


Com o entendimento de que:

    Você libera suas contribuições sob licença livre — você geralmente deverá licenciar suas edições e contribuições a nossos projetos sob uma licença livre e aberta, salvo suas contribuições estiverem em domínio público.
    Ausência de aconselhamento profissional — o conteúdo dos artigos e outros projetos tem o propósito apenas informativo, e não constitui aconselhamento profissional.



Nossos termos e condições de uso

Imagine um mundo onde todos os seres humanos possam compartilhar livremente a soma de todo conhecimento. Este é o nosso compromisso. – Nossa Visão

Bem-vindo(a) à Wikimedia! A Wikimedia Foundation, Inc. é uma organização filantrópica sem fins lucrativos cuja missão é capacitar e engajar pessoas de todo o mundo para coletar e desenvolver conteúdo sob uma licença livre ou em domínio público e disseminá-lo de maneira eficiente e global, sem custos.

Para apoiar nossa vibrante comunidade, proporcionamos a infraestrutura e estrutura organizacional básicas para o desenvolvimento de projetos wikis multilíngues e suas edições (como explicado aqui) e outros empreendimentos que atendem a esta missão. Nós nos esforçamos para disponibilizar e manter conteúdos educacionais e informativos dos projetos na internet sem custos, em caráter perpétuo.

Nós lhe damos boas-vindas ("você" ou "usuário") como leitor, editor, autor ou colaborador dos projetos Wikimedia e o encorajamos a fazer parte da comunidade Wikimedia. Antes de participar, contudo, solicitamos que leia e concorde com os termos de uso ("termos de uso") a seguir.
Visão geral

Estes termos de uso informam sobre nossos serviços públicos na Fundação Wikimedia, nosso relacionamento com você como usuário e os direitos e responsabilidades que guiarão a ambos. Queremos que você saiba que hospedamos uma quantidade incrível de conteúdo educacional e informativo, fruto da contribuição e graças aos usuários como você. Em geral, não contribuímos com conteúdo nem monitoramos ou excluímos conteúdo (com a rara exceção de políticas como estes Termos de uso ou para fins de conformidade legal em caso de notificações referentes à DMCA). Isso significa que o controle editorial está nas suas mãos e nas mãos dos seus amigos usuários, que criam e gerenciam conteúdo. Nós apenas hospedamos esse conteúdo.

A comunidade - a rede de usuários que estão constantemente construindo e usando os vários sites ou projetos - é o principal meio pelo qual as metas da missão são alcançadas. A comunidade contribui e ajuda a administrar nossos sites. A comunidade empreende a função crucial de criar e fazer valer as políticas para as edições de projetos específicos (tais como a edição em diferentes idiomas do projeto Wikipédia ou a edição multilíngue do Wikimedia Commons).

Você está convidado a participar como colaborador, editor, ou autor, mas você deve seguir as políticas que regem cada uma das edições independente do Projeto. O maior dos nossos projetos é a Wikipedia, mas hospedamos outros projetos também, cada um com diferentes objetivos e métodos de trabalho. Cada edição do projeto conta com uma equipe de colaboradores, editores e autores que trabalham em conjunto para criar e gerenciar o conteúdo naquele projeto. Você está convidado a juntar-se a essas equipes e trabalhar com elas para melhorar esses projetos. Porque nos dedicamos a tornar o conteúdo livremente acessível ao público, isso geralmente exige que todo o conteúdo que contribuir está disponível sob uma licença livre ou de domínio público.

Esteja ciente de que você é legalmente responsável por todas as suas contribuições, edições e reutilização de conteúdo da Wikimedia sob as leis dos Estados Unidos da América e outras leis aplicáveis (o que pode incluir as leis de onde você vive ou de onde você visualiza ou edita conteúdo). Isso significa que é importante ter cautela ao publicar conteúdo. À luz dessa responsabilidade, temos algumas regras sobre o que você não pode publicar. A maioria delas é para sua proteção ou para a proteção de outros usuários como você. Tenha em mente que o conteúdo que hospedamos é somente para fins de informação geral. Assim, caso você precise de aconselhamento especializado para uma questão específica (tais como questões médicas, jurídicas ou financeiras), você deverá buscar a ajuda de um profissional licenciado ou qualificado. Também incluímos outros avisos importantes e isenções de responsabilidade. Assim, leia esses termos de uso, integralmente.

Para que fique claro: outras organizações, tais como divisões e associações locais da Wikimedia, que podem compartilhar da mesma missão, são, ainda assim, legalmente independentes e separadas da Fundação Wikimédia e não têm responsabilidade sobre as operações do website ou o seu conteúdo.
Contents

    Visão geral
    1. Nossos serviços
    2. Política de privacidade
    3. Conteúdo que nós hospedamos
    4. Atividades a serem evitadas
    5. Segurança de sua senha
    6. Marcas comerciais
    7. Licenciamento de conteúdo
    8. Conformidade com o DMCA
    9. Websites e recursos de terceiros
    10. Administração dos websites
    11. Resoluções e políticas dos projetos
    12. Rescisão
    13. Disputas e jurisdição
    14. Renúncias
    15. Limitação de responsabilidade
    16. Modificações a estes termos de uso
    17. Outros termos
    Obrigado!

1. Nossos serviços

A Fundação Wikimedia é dedicada a incentivar o crescimento, o desenvolvimento e a distribuição de conteúdo multilíngue livre e hospedar o conteúdo completo desses projetos baseados em wiki para o público gratuitamente. Nosso papel é acolher alguns dos maiores projetos de referência editados colaborativamente em todo o mundo, que podem ser encontradosaqui. No entanto, agimos apenas como um serviço de hospedagem, mantendo a infra-estrutura e a estrutura organizacional que permite aos nossos usuários construirem os projetos da Wikimedia, contribuindo com a edição de conteúdo. Por causa de nosso papel único, há algumas coisas que você deve estar ciente ao considerar nossa relação com vocês, os projetos e os outros usuários:

    Nós não assumimos um papel editorial: Porque os projetos da Wikimedia são editados colaborativamente, todo o conteúdo que hospedamos são fornecidos por usuários como você e nós não temos um papel editorial. Isso significa que nós geralmente não monitoramos ou editamos o conteúdo dos sites do projeto e não assumimos qualquer responsabilidade por estes conteúdos. Da mesma forma, nós não endossamos quaisquer opiniões expressas por meio de nossos serviços e não garantimos a veracidade, exatidão ou a confiabilidade de qualquer conteúdo que foi submetido pela comunidade. Em vez disso, nós apenas fornecemos acesso ao conteúdo que seus colegas usuários têm contribuído e editado.
    Você é responsável por suas próprias ações: você é legalmente responsável por suas edições e contribuições em projetos da Wikimedia, então para sua própria proteção, você deve ter cautela e evitar qualquer conteúdo que possa resultar em responsabilidade civil ou criminal sob as leis aplicáveis a contribuir. Para maior clareza, a lei aplicável inclui pelo menos as leis dos Estados Unidos da América. Embora nós não podemos concordar com tais ações, advertimos editores e colaboradores que as autoridades podem tentar aplicar outras leis do país, incluindo as leis locais onde você mora ou onde você visualizar ou editar o conteúdo. WMF geralmente não pode oferecer qualquer proteção, a garantia, a imunidade ou a indenização.

2. Política de privacidade

Pedimos que reveja os termos de nossa política de privacidade, para que você esteja ciente de como coletamos e usamos suas informações. Porque nossos serviços são utilizados por pessoas de todo o mundo, as informações pessoais que coletamos podem ser armazenadas e processadas nos Estados Unidos da América ou qualquer outro país em que nós ou os nossos agentes mantenham instalações. Usando nossos serviços, você concorda com qualquer transferência de informações fora do seu país.

3. Conteúdo que nós hospedamos

    Você pode achar alguns materiais objetáveis ou errôneos: uma vez que proporcionamos uma ampla gama de conteúdo produzido ou coletado por usuários, você poderá encontrar materiais que considera ofensivos, errôneos, enganosos, erroneamente rotulados ou de outra maneira objetáveis. Solicitamos, assim, que você use o bom senso e julgue por si mesmo ao usar os nossos serviços.
    Nosso conteúdo é somente para fins de informação geral: ainda que hospedemos uma grande quantidade de informações que dizem respeito a tópicos profissionais, incluindo questões médicas, legais e financeiras, este conteúdo é apresentado somente para fins de informação geral. Ele não deve ser entendido como aconselhamento profissional. Busque aconselhamento profissional independente de alguém licenciado ou qualificado na área em questão em vez de agir com base em qualquer informação, opinião ou conselho contido em nos websites dos projetos.

4. Atividades a serem evitadas

Os Projetos hospedados pela Wikimedia Foundation somente existem devido à vibrante comunidade de usuários como você que colaboram juntos para escrever, editar e manter o conteúdo. Ficamos felizes em dar boas-vindas à sua participação nesta comunidade. Nós o encorajamos a ser civilizado e educado nas suas interações com a comunidade, a agir de boa-fé e fazer edições e colaborações com o fim de promover a missão do Projeto compartilhado.

Certas atividades, sejam legais ou ilegais, podem ser prejudiciais a outros usuários e violar nossas regras. Algumas atividades podem ainda sujeitá-lo a responsabilização civil. Assim, para a sua própria proteção e para a de outros usuários, você não pode participar de tais atividades nos nossos sites. Essas atividades incluem:

    Assediar terceiros e tratá-los de maneira abusiva

            participar de assédio, ameaças, perseguição, envio de spam ou vandalismo; e
            transmitir e-mails com correntes, publicidade ou spam para outros usuários.

    Violar a privacidade de terceiros

            infringir os direitos de privacidade de terceiros sob as leis dos Estados Unidos da América ou outras leis aplicáveis (que podem incluir as leis de onde você vive ou de onde você visualiza ou edita conteúdo);
            solicitar informações pessoalmente identificáveis com o fim de assédio, exploração, violação da privacidade ou qualquer fim de promoção comercial não explicitamente aprovado pela Wikimedia Foundation; e
            solicitar informações pessoalmente identificáveis de qualquer pessoa com menos de 18 anos de idade para fins ilegais ou violação de qualquer lei aplicável referente à saúde ou ao bem-estar de menores.

    Realizar afirmações falsas, se fazer passar por terceiros ou realizar fraude

            postar conteúdo, de maneira intencional ou deliberada, que constitua calúnia ou difamação;
            com o fim de enganar, postar conteúdo que seja falso ou impreciso;
            tentar se fazer passar por outro usuário ou indivíduo, indicar de maneira enganosa sua afiliação a qualquer indivíduo ou entidade ou usar o sobrenome de outro usuário com o objetivo de enganar; e
            participar de fraudes.

    Cometer infração

            infringir direitos autorais, marcas comerciais, patentes ou outros direitos de propriedade sob as leis aplicáveis.

    Fazer mau uso dos nossos serviços para outros fins ilegais

            postar pornografia infantil ou qualquer outro conteúdo que viole as leis aplicáveis referentes à pornografia infantil;
            postar ou transmitir materiais obscenos que sejam ilegais sob as leis aplicáveis; e
            usar os serviços de maneira que seja inconsistente com a lei aplicável.

    Realizar uso disruptivo ou mau uso ilegal de instalações

            postar ou distribuir conteúdo que contenha vírus, malware, worms, cavalos-de-troia, código malicioso ou outros dispositivos que possam danificar nossa infraestrutura técnica ou sistema ou os dos nossos usuários;
            realizar uso automatizado do site que seja abusivo ou interrompa os serviços e não tenha sido aprovado pela comunidade Wikimedia;
            interromper os serviços colocando uma carga indevida no website de um projeto ou nas redes ou servidores conectados ao website de um projeto;
            interromper os serviços inundando qualquer um dos websites de projeto com comunicações ou outros tipos de tráfego que sugiram a ausência de uma intenção séria de usar o website do projeto para o seu fim declarado;
            de maneira deliberada, interferir com ou usar qualquer uma das áreas não públicas dos nossos sistemas computadorizados sem autorização; e
            sondar, analisar ou testar a vulnerabilidade de qualquer um dos nossos sistemas técnicos ou redes a menos que todas as condições a seguir sejam atendidas:

                tais ações não abusem de maneira indevida ou interrompam nossos sistemas técnicos ou redes;
                tais ações não visem o ganho pessoal (exceto para o crédito do seu trabalho);
                você relate as vulnerabilidades a desenvolvedores do MediaWiki (ou as corrija você mesmo); e
                você não realize tais ações com intenção maliciosa ou destrutiva.

    Contribuições pagas sem divulgação

Estes termos de uso proíbem o engajamento em atividades enganosas, incluindo declaração de falsa de afiliação, passar-se por outra pessoa e fraude. Para garantir o cumprimento dessas obrigações, você deve revelar seu empregador, cliente e afiliação referente a qualquer contribuição para todos os projetos Wikimedia para o qual você receber, ou espera receber, compensação. Você deve fazer essa revelação em pelo menos uma das seguintes maneiras:

        * uma declaração na sua página de usuário,
        * uma declaração na página de discussão que acompanha quaisquer contribuições pagas, ou
        * uma declaração no sumário de edição que acompanha quaisquer contribuições pagas.

        A legislação aplicável, ou as políticas e diretrizes da comunidade e da Fundação, como as que tratam de conflitos de interesse, podem limitar ainda mais as contribuições pagas ou exigir uma divulgação mais detalhada.
        Uma comunidade de um Projeto Wikimedia pode adotar uma política alternativa de divulgação de contribuições pagas. Se um projeto adota uma política de divulgação alternativa, você pode cumprir essa política em vez dos requisitos desta seção ao contribuir para esse projeto. Uma política alternativa de contribuição paga só substituirá esses requisitos se for aprovada pela comunidade relevante do Projeto e listada na página de alternativas da política de divulgação.

Se desejar mais informações, por favor leia Perguntas frequentes sobre divulgação de contribuições pagas.

Nós nos reservamos o direito de aplicar o nosso entendimento na execução dos termos acima.

5. Segurança de sua senha

Você é responsável pela segurança de sua própria senha e nunca deverá revelá-la a terceiros.

6. Marcas comerciais

Ainda que você tenha liberdade considerável para reutilizar o conteúdo dos websites dos projetos, é importante que, na Fundação Wikimedia, protejamos nossos direitos de marcas comerciais de forma que possamos proteger nossos usuários de fraudadores. Por isso, solicitamos que você respeite nossas marcas comerciais. Todas as marcas comerciais da Fundação Wikimedia pertencem à fundação e toda utilização dos nossos nomes comerciais, marcas comerciais, marcas de serviço, logotipos ou nomes de domínio deve ocorrer em conformidade com estes termos de uso e em conformidade com nossa Política de marcas comerciais.

7. Licenciamento de conteúdo

Para promover os patrimônios comuns de conhecimento e cultura livres, exige-se que todos os usuários que contribuem com os projetos cedam permissões amplas ao público em geral para redistribuir e reutilizar as contribuições deles de maneira livre, desde que esse uso seja apropriadamente reconhecido e a mesma liberdade de reutilização e redistribuição seja cedida a todas as obras derivadas. Em concordância com nossa meta de proporcionar informações livres ao público mais amplo possível, solicitamos que, quando necessário, todo conteúdo submetido seja licenciado de maneira a ser livremente reutilizável por qualquer um que se dê ao trabalho de acessá-lo.

Você concorda com os seguintes requisitos de licenciamento:

    Textos sobre os quais você detém os direitos de autor: quando submeter textos sobre os quais você detém os direitos de autor, você concorda em licenciá-lo sob:
        Licença Creative Commons Atribuição - Partilha nos Mesmos Termos 3.0 Não Adaptada (“CC BY-SA”), e
        Licença GNU de Documentação Livre (“GFDL”) (não versionada, sem seções invariantes, sem textos de capa ou contra-capa).
    (Os usuários que fizerem reutilização poderão agir em conformidade com uma das licenças ou com as duas.)

    A única exceção é caso a edição do Projeto ou recurso exija uma licença diferente. Nesse caso, você concorda em licenciar qualquer texto com o qual contribuir sob essa licença em particular. Por exemplo, na publicação desta versão dos termos de uso, a versão anglófona do Wikinews determina que todo conteúdo no formato texto seja licenciado sob a Creative Commons Attribution 2.5 Generic License (CC BY 2.5) e não exige uma licença dual com a GFDL.

    Observe que essas licenças permitem usos comerciais das suas contribuições, desde que tais usos sejam compatíveis com os termos.
    Atribuição: a atribuição é uma parte importante dessas licenças. Consideramos isso dando crédito onde o crédito é devido – a autores como você. Quando você contribui com texto, concorda que o mesmo lhe seja atribuído de qualquer uma das seguintes maneiras:
        Através de hiperligação (quando possível) ou URL para o artigo ao qual você contribuiu (visto que cada artigo tem um histórico que lista todos os autores e editores);
        Através de hiperligação (quando possível) ou URL para uma alternativa, a cópia on-line estável, que é de livre acesso e está de acordo com a licença, fornecendo crédito aos autores de uma forma equivalente ao crédito dado no site do Projeto; ou
        Através de uma lista de todos os autores (mas por favor, note que qualquer lista de autores pode ser filtrada para excluir contribuições muito pequenas ou irrelevantes).
    Importação de textos: você pode importar texto que tiver encontrado em outros lugares ou dos quais for co-autor com terceiros, mas em tal caso você garante que o texto está disponível sob termos compatíveis com a licença CC BY-SA 3.0 (ou, como explicado acima, outra licença, quando excepcionalmente exigido pela edição do projeto ou recurso) ("CC BY-SA"). Não é permitido conteúdo disponível somente sob a GFDL.


    Você concorda que, se você importar texto sob uma CC BY-SA licença que exija atribuição, você deve creditar o autor (s) de uma forma razoável. Onde tal crédito é comumente dada através de histórias de página (como Wikimedia-interno cópia), é suficiente para dar atribuição no sumário de edição, que é gravado no histórico da página, ao importar o texto. Os requisitos de atribuição são por vezes demasiado intrusiva para circunstâncias particulares (independentemente da licença), e pode haver casos em que a comunidade Wikimedia decide que o texto importado não pode ser usado por esse motivo.
    Mídias não textuais: mídias não textuais nos projetos estão disponíveis sob uma diversidade de licenças que dão suporte à meta geral de permitir reutilização e redistribuição irrestritas. Quando você contribui com mídias não textuais, você concorda em respeitar as exigências das licenças descritas na nossa Política de licenciamento e também agir em conformidade com as exigências da edição do projeto ou recurso específico para o qual estiver contribuindo. Veja também a Política de licenciamento da Wikimedia Commons para obter mais informações sobre como contribuir para o projeto com mídias em formatos não textuais.
    Sem revogação da licença: Exceto como consistente com a sua licença, você concorda que você não vai unilateralmente revogar ou buscar a invalidação de qualquer licença que você tiver concedido sob estes Termos de Uso para conteúdo de texto ou mídia não textual contribuíram para os projetos da Wikimedia ou recursos, mesmo se você terminar utilização dos nossos serviços.
    Conteúdo de domínio público: O conteúdo que está no domínio público é bem-vindo! Contudo, é importante que você confirme o status de domínio público do conteúdo sob a lei dos Estados Unidos da América, bem como as leis de quaisquer outros países, conforme exigido pela edição específica do projeto. Quando você contribuir com conteúdo que está no domínio público, você garante que o material é realmente no domínio público, e você concorda em rotulá-la de forma adequada.
    Reutilização: a reutilização do conteúdo que hospedamos é bem-vinda, ainda que existam exceções para conteúdos fruto de contribuição sob "uso justo" ou outras isenções conformes à lei de direitos autorais. Qualquer reutilização deverá respeitar a(s) licença(s) subjacente(s).

    Quando você reutilizar ou redistribuir uma página de texto desenvolvida pela comunidade da Wikimedia, você concorda fazer atribuição aos autores de qualquer uma das seguintes maneiras:
        Através de hiperligação (quando possível) ou URL para o artigo ao qual você contribuiu (visto que cada artigo tem um histórico que lista todos os autores e editores);
        Através de hiperligação (quando possível) ou URL para uma alternativa, a cópia on-line estável, que é de livre acesso e está de acordo com a licença, fornecendo crédito aos autores de uma forma equivalente ao crédito dado no site do Projeto; ou
        Através de uma lista de todos os autores (mas por favor, note que qualquer lista de autores pode ser filtrada para excluir contribuições muito pequenas ou irrelevantes).

    Se o conteúdo do texto foi importado de outra fonte, é possível que o conteúdo esteja sob uma licença compatível CC BY-SA, mas não com GFDL (conforme descrito acima em "Importar texto"). Nesse caso, você concorda em cumprir com a compatibilidade da licença CC BY-SA, sem ter a opção de relicençar sob GFDL. Para determinar a licença que se aplica ao conteúdo que você procura para reutilização ou redistribuição, deverá rever o rodapé da página, o histórico e a página de discussão.

    Além disso, esteja ciente de que textos originados de fontes externas e importados para o projeto podem estar sob uma licença com exigências adicionais de atribuição. Os usuários concordam em indicar essas exigências de atribuição adicionais de maneira clara. Dependendo do projeto, tais exigências podem aparecer, por exemplo, em um banner ou outras anotações indicando que parte ou todo o conteúdo foi originalmente publicado em outro lugar. Onde houver tais anotações visíveis, os usuários deverão preservá-las.
    No caso de qualquer mídia não textual, você concorda em respeitar qualquer licença sob a qual a obra tiver sido disponibilizada (o que pode ser descoberto clicando na obra e observando a seção de licenciamento na sua página de descrição ou analisando uma página de origem aplicável para essa obra). Ao reutilizar qualquer conteúdo hospedado por nós, você concorda com as exigências de atribuição relevantes conforme a licença ou licenças subjacentes.
    Modificações ou adições a materiais que você reutiliza: ao modificar ou fazer adições a texto que você obteve de um website do projeto, você concorda em licenciar o conteúdo modificado ou adicionado sob uma licença CC BY-SA 3.0 ou posterior (ou, como explicado acima, outra licença, quando excepcionalmente exigido pelo Projeto ou recurso específico).

    Ao modificar ou fazer adições a qualquer mídia não textual que você tiver obtido de um website do projeto, você concorda em licenciar o conteúdo modificado ou adicionado de acordo com qualquer licença sob a qual a obra tiver sido disponibilizada.

    Tanto no caso de conteúdo textual quanto no de qualquer outro tipo de mídia não textual, você concorda em indicar claramente que a obra original foi modificada. Caso você esteja reutilizando conteúdo de uma wiki, será suficiente indicar no histórico da página que você fez uma alteração no texto importado. Para cada cópia ou versão modificada que você distribuir, você concorda em incluir uma notificação de licença declarando sob qual licença o trabalho foi divulgado, junto com um hyperlink ou URL para o texto da licença ou uma cópia da própria licença.

8. Conformidade com o DMCA

A Wikimedia Foundation quer assegurar que o conteúdo que hospedamos possa ser reutilizado por outros usuários sem medo de responsabilização civil e que não ocorra infringimento dos direitos de propriedade de terceiros. Para agir de maneira justa perante os nossos usuários, bem como outros criadores e detentores de direitos autorais, nossa política é responder somente a notificações de suspeitas de infringimento que se conformem às formalidades da Lei dos direitos autorais do milênio digital (DMCA) [Digital Millennium Copyright Act, DMCA]. De acordo com a DMCA, nós excluiremos, nas circunstâncias apropriadas, usuários e titulares de contas do nosso sistema e da nossa rede que reincidirem em infrações.

Contudo, também reconhecemos que nem todas as notificações de infringimento são válidas ou feitas de boa-fé. Em tais casos, recomendamos veementemente os usuários a protocolar contra-notificações quando acreditarem que uma notificação de infringimento de acordo com a DMCA é inválida ou imprópria. Para obter mais informações sobre o que fazer caso ache que uma notificação baseada na DMCA foi protocolada de maneira imprópria, você pode querer consultar o website Lumen Database (anteriormente conhecido como Chilling Effects).

Caso seja proprietário de conteúdo que esteja sendo usado impropriamente em um dos projetos sem sua permissão, você pode solicitar que o conteúdo seja removido de acordo com a DMCA. Para fazer uma solicitação deste tipo, envie-nos um e-mail para legal @ wikimedia.org ou carta convencional para o nosso agente designado neste endereço.

Alternativamente, você pode fazer uma solicitação à nossa comunidade, que frequentemente cuida de questões de direitos autorais de maneira mais rápida e eficaz do que o prescrito pela DMCA. Nesse caso, você poderá postar um aviso explicando suas preocupações relativas aos direitos autorais. Para obter uma lista não exaustiva e não oficial dos processos relevantes para as diferentes edições de projeto, olhe aqui. Antes de protocolar uma reclamação baseada na DMCA, você também tem a opção de enviar um e-mail para a comunidade em info @ wikimedia.org.

9. Websites e recursos de terceiros

Você será o único responsável pelo uso que fizer de websites ou recursos de terceiros. Ainda que os projetos contenham links para websites e recursos de terceiros, não endossamos nem somos co-responsáveis ou imputáveis pela sua disponibilidade, precisão ou pelo conteúdo, produtos ou serviços relacionados (incluindo, entre outros, quaisquer vírus ou outros recursos prejudiciais), nem temos qualquer obrigação de monitorar tais conteúdos de terceiros.

10. Administração dos websites

A comunidade tem o papel principal na criação e na execução de políticas aplicáveis às diferentes edições de projetos. Na Wikimedia Foundation, raramente intervimos em decisões comunitárias sobre políticas e sua execução. Em casos incomuns, a necessidade pode surgir, ou a comunidade pode nos solicitar, entrar em contato com um usuário especialmente problemático devido à perturbação significativa de um projeto ou comportamento perigoso. Em tais casos, nós nos reservamos o direito, mas não temos a obrigação de:

    investigar sua utilização do serviço (a) para determinar se violações destes termos de uso, da política de edição de projetos ou outras leis ou políticas aplicáveis ocorreram ou (b) para agir em conformidade com qualquer lei, processo legal ou solicitação governamental apropriada;
    detectar, prevenir ou de qualquer outra maneira responder a fraude, segurança ou questões técnicas ou atender solicitações de suporte ao usuário;
    recusar, desativar ou restringir o acesso às contribuições de qualquer usuário que violem estes termos de uso;
    banir usuários de maneira a impedi-los de de editar ou contribuir ou bloquear contas ou o acesso de usuários por ações que violem estes termos de uso, incluindo repetidas ações de infringimento dos direitos autorais;
    tomar medidas legais contra usuários que violarem estes termos de uso (incluindo comunicações a autoridades policiais); e
    administrar os websites dos projetos de uma maneira elaborada para facilitar seu funcionamento apropriado e proteger os direitos, a propriedade e a segurança nossas e dos nossos usuários, licenciadores, parceiros e do público.

No interesse dos nossos usuários e dos projetos, na circunstância extrema de qualquer indivíduo ter sua conta ou acesso bloqueado sob esta provisão, ele estará proibido de criar ou usar outra conta ou de buscar acesso ao mesmo projeto, a menos que proporcionemos permissão expressa. Sem limitar a autoridade da comunidade, a própria Wikimedia Foundation não banirá usuários de maneira a impedi-los de editar ou contribuir nem bloqueará contas ou acessos de usuários somente por conta de críticas feitas de boa-fé que não resultem em ações que de qualquer outra maneira violem estes termos de uso ou as políticas da comunidade.

A comunidade da Wikimedia e seus membros também podem tomar medidas quando isso for autorizado pela comunidade ou pelas políticas da fundação aplicáveis à edição específica de projeto, incluindo, entre outras, alertar, investigar, bloquear ou banir usuários que violarem essas políticas. Você concorda em respeitar as decisões finais de corpos de resolução de disputas que forem estabelecidos pela comunidade para as edições de projeto específicas (tais como comitês de arbitramento). Essas decisões poderão incluir sanções conforme definido pela política da edição específica do projeto.

Usuários especialmente problemáticos que tiverem suas contas ou acesso bloqueado em múltiplas edições de projetos podem ficar sujeitos a banimento de todas as edições de projeto, de acordo com a Política global de banimento. Em contraste com resoluções do conselho ou estes termos de uso, as políticas estabelecidas pela comunidade, que podem cobrir uma única edição de projeto ou múltiplas edições de projeto (como a Política global de banimento), podem ser modificadas pela comunidade relevante de acordo com os seus próprios procedimentos.

O bloqueio de contas ou acesso ou o banimento de usuários sob esta provisão se dará de acordo com a Seção 12 destes termos de uso.

11. Resoluções e políticas dos projetos

O conselho de curadores da Wikimedia Foundation emite políticas oficiais periodicamente. Algumas dessas políticas podem ser obrigatórias para um projeto particular ou edição de projeto e, quando esse for o caso, você concorda em respeitá-las como elas se aplicarem.

12. Rescisão

Ainda que esperemos que você permaneça e continue a contribuir com os projetos, você pode parar de usar nossos serviços a qualquer momento. Em certas circunstâncias (que esperamos improváveis), pode ser necessário para nós mesmos, para a comunidade da Wikimedia ou seus membros (como descrito na Seção 10), interromper nossos serviços de maneira integral ou parcial, rescindir estes termos de uso, bloquear sua conta ou acesso ou bani-lo como usuário. Caso sua conta ou acesso sejam bloqueados ou de outra maneira suprimidos por qualquer razão, suas contribuições públicas permanecerão publicamente disponíveis (o que estará sujeito às políticas aplicáveis), mas, a não ser que o notifiquemos de outra forma, você ainda poderá acessar nossas páginas públicas com o único fim de ler conteúdo publicamente disponível nos projetos. Em tais circunstâncias, contudo, você poderá não ser capaz de acessar sua conta ou suas configurações. Nós nos reservamos o direito de suspender ou finalizar os serviços a qualquer momento, com ou sem causa e com ou sem aviso. Mesmo após sua utilização e participação serem interrompidas, bloqueadas ou de qualquer outra maneira suspensas, estes termos de uso permanecerão em vigor no que se refere a provisões relevantes, incluindo as Seções 1, 3, 4, 6, 7, 9-15 e 17.

13. Disputas e jurisdição

Destacado para dar ênfase

Esperamos que não ocorra nenhum desentendimento sério envolvendo você, mas, caso ocorram disputas, nós o encorajamos a buscar resolução através dos procedimentos ou mecanismos de resolução de disputas proporcionados pelos projetos ou edições de projetos e pela Wikimedia Foundation. Caso você queira entrar com uma ação jurídica contra nós, concorda em protocolá-la e resolvê-la exclusivamente em um tribunal estadual ou federal localizado no condado de São Francisco, Califórnia. Você também concorda que as leis do estado da Califórnia e, na medida em que isso se aplicar, as leis dos Estados Unidos da América, regerão estes termos de uso, bem como qualquer legal reivindicação que possa se originar entre você e nós (sem considerar as regras governando os conflitos entre leis). Você concorda em se submeter à jurisdição pessoal de e concorda com a jurisdição dos tribunais localizados no condado de São Francisco, Califórnia, em qualquer ação jurídica ou procedimento referente a nós ou a estes termos de uso.

Para garantir que as disputas sejam resolvidas assim que surgirem, você concorda que, a despeito de qualquer estatuto ou lei em contrário, qualquer reivindicação ou causa de ação que você possa ter originada dos ou relacionada ao uso dos nossos serviços de acordo com estes termos de uso deverá ser protocolada nos limites do estatuto de prescrições aplicável ou, caso ocorra antes, um (1) ano após os fatos pertinentes subjacentes a tal reivindicação ou causa de ação poderem ter sido descobertos mediante diligência razoável (ou serem para sempre suprimidos).

14. Renúncias

Destaque para ênfase

Na Fundação Wikimedia, fazemos o possível para oferecer conteúdo educacional e informativo a uma audiência muito ampla, mas você faz uso dos nossos serviços por sua própria conta e risco. Proporcionamos esses serviços "como são" e "conforme disponibilizados", e nos isentamos expressamente de todas as garantias expressas ou implícitas de todos os tipos, incluindo, mas não limitadas às, garantias implícitas de comerciabilidade, adequabilidade para um fim particular e não infringimento. Não damos garantias de que nossos serviços atenderão suas exigências, serão seguros, ininterruptos, tempestivos, precisos ou livres de erros ou de que suas informações estarão seguras.

Não somos responsáveis por conteúdos, dados ou ações de terceiros e você nos isenta, e a nossos diretores, executivos, funcionários e agentes, de todas as reivindicações ou danos, conhecidos e desconhecidos, decorrentes de ou de qualquer maneira relacionados com qualquer reivindicação que você possa ter contra tais terceiras partes. Nenhum aconselhamento ou informação, seja oral ou por escrito, obtido por você de nós ou através dos nossos serviços, cria qualquer garantia não expressamente declarada nestes termos de uso.

Qualquer material descarregado ou obtido através da utilização de nossos serviços é feito por sua própria conta e risco, e você será o único responsável por qualquer dano ao seu sistema de computador ou perda de dados resultante da descarga de qualquer material desse tipo. Você concorda que não temos responsabilidade ou imputabilidade pela exclusão de, ou pela falha em armazenar ou transmitir, qualquer conteúdo ou comunicação mantida pelo serviço. Reservamo-nos o direito de estabelecer limites ao uso e ao armazenamento a nosso critério exclusivo em qualquer momento, com ou sem aviso prévio.

Alguns estados ou jurisdições não permitem os tipos de isenções de responsabilidade nesta seção. Assim, elas podem não se aplicar a você em parte ou na íntegra, dependendo da lei.

15. Limitação de responsabilidade

Destacado para dar ênfase
A Wikimedia Foundation não será responsável perante você ou qualquer outra parte por qualquer dano direto, indireto, especial, consequencial ou exemplar, incluindo, entre outros, danos por lucros cessantes, boa-fé, uso, dados ou outras perdas intangíveis, independente de termos sido avisados da possibilidade de tais danos. Em nenhuma circunstância, nossa responsabilidade ultrapassará mil dólares norte-americanos (US$ 1.000,00) no total. Caso a legislação aplicável não permita a limitação ou exclusão da responsabilidade ou de dados incidentais ou consequenciais, a limitação ou exclusão acima poderá não se aplicar a você, ainda que nossa responsabilidade seja limitada na medida máxima possível autorizada pela legislação aplicável.

16. Modificações a estes termos de uso

Assim como a contribuição da comunidade Wikimedia é essencial para o crescimento e a manutenção dos projetos, acreditamos que a contribuição da comunidade é essencial para que estes termos de uso sirvam adequadamente aos nossos usuários. Isso também é essencial para um contrato justo. Portanto, forneceremos esses termos de uso, bem como quaisquer revisões substanciais futuras destes termos de uso, à comunidade para comentários, pelo menos trinta (30) dias antes do final do período de comentários. Caso uma futura proposta de revisão for substancial, forneceremos 30 dias adicionais para comentários após a publicação de uma tradução da revisão proposta em pelo menos três idiomas (selecionados a nosso critério). A comunidade será encorajada a traduzir a revisão proposta em outros idiomas conforme apropriado. Para alterações por razões legais ou administrativas, para corrigir uma declaração imprecisa ou alterações em resposta a comentários da comunidade, forneceremos um aviso com pelo menos três (3) dias de antecedência.

Uma vez que pode ser necessário modificar estes Termos de Uso periodicamente, iremos fornecer notificação de tais modificações e a oportunidade de comentar através dos sites dos projetos e por meio de uma notificação em WikimediaAnnounce-L. No entanto, solicitamos que você examine periodicamente a versão mais atualizada destes termos de uso (disponível em http://wikimediafoundation.org/wiki/Terms of use). O seu uso continuado dos nossos serviços após os novos termos de uso serem oficializados após o aviso e o período de revisão constitui uma aceitação destes termos de uso da sua parte. Para proteger a Wikimedia Foundation e outros usuários como você, se você não concordar com nossos termos de uso, você não poderá usar nossos serviços.

17. Outros termos

Estes termos de uso não criam relação de emprego, agência, parceria ou joint venture entre você e nós, a Wikimedia Foundation. Caso você não tenha assinado um contrato em separado conosco, estes termos de uso serão a íntegra do acordado entre nós. Caso exista qualquer conflito entre estes termos de uso e um contrato escrito assinado entre nós, o contrato assinado terá precedência.

Você concorda que nós poderemos lhe fornecer notificações, incluindo com referência a alterações destes termos de uso, por e-mail, correio tradicional ou postagens em websites do projeto.

Se, em qualquer circunstância, não aplicarmos ou executarmos qualquer provisão destes termos de uso, isso não significará uma renúncia a esta provisão.

Você entende que, exceto de outra forma acordado por nós por escrito, você não tem expectativa de remuneração por qualquer atividade, contribuição ou ideia que oferecer a nós, à comunidade, aos projetos da Wikimedia ou às edições do projeto.

A despeito de quaisquer provisões em contrário nestes termos de uso, nós (a Wikimedia Foundation) e você concordamos em não modificar os termos e as exigências aplicáveis de qualquer licença livre empregada nos projetos ou edições de projetos quando tais licenças livres forem autorizadas por estes termos de uso.

Estes termos de uso foram escritos em inglês (norte-americano). Esperamos que as traduções destes termos de uso sejam precisas. Em caso de diferenças de significado entre a versão original em inglês e uma tradução, a versão original em inglês terá precedência.

Caso qualquer provisão ou partes destes termos de uso seja considerada ilegal, inválida ou inexecutável, essa provisão ou parte da provisão será considerada independente destes termos de uso e será executada somente na extensão máxima permitida e todas as outras provisões destes termos de uso permanecerão em pleno vigor.
Obrigado!

Apreciamos o fato de você ter se dado ao trabalho de ler esses termos de uso e ficamos muito felizes por você estar contribuindo com os projetos e usando nossos serviços. Obrigado pelas suas contribuições. Você está ajudando a construir algo realmente grande – não somente uma importante coleção de projetos de referência editados em colaboração, que proporcionam educação e informação a milhões, que, de outra forma, poderiam não ter acesso – mas também uma vibrante comunidade de pessoas de mentalidade semelhante focadas em um objetivo muito nobre.

Esses Termos de Uso entraram em vigência em 16 de junho de 2014. Versões anteriores desses termos:

    Termos de Uso (2012-2014): vigentes de 24 de maio de 2012 a 16 de junho de 2014
    Termos de Uso (2009): vigentes de 2009 até 24 de maio de 2012.

Por favor, note que em caso de diferenças no significado ou na interpretação entre a versão original inglesa desta diretriz e sua tradução, considere a versão original. " << endl;
    exit();
    }else {
        file.open(auth.txt, ios::trunc)
        cout << "資料已刪除，請重新生成金鑰" << endl;
        exit();
    }
}

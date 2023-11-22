import 'package:cred/utils/constants.dart';
import 'package:cred/utils/size_config.dart';
import 'package:cred/widgets/first_child.dart';
import 'package:cred/widgets/second_child.dart';
import 'package:flutter/material.dart';

class PrimaryScreen extends StatefulWidget {
  const PrimaryScreen({super.key});

  @override
  State<PrimaryScreen> createState() => _PrimaryScreenState();
}

class _PrimaryScreenState extends State<PrimaryScreen> {
  var isFirstWidgetOpen = false;
  var isSecondWidgetOpen = false;
  openFirstChild() {
    setState(() {
      isFirstWidgetOpen = true;
    });
  }

  closeFirstChild() {
    setState(() {
      isFirstWidgetOpen = false;
    });
  }

  openSecondChild() {
    setState(() {
      isSecondWidgetOpen = true;
    });
  }

  closeSecondChild() {
    setState(() {
      isSecondWidgetOpen = false;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: primaryBlueBg,
      appBar: AppBar(
        actions: [
          IconButton(
            onPressed: () {},
            icon: const Icon(Icons.close),
          ),
          IconButton(onPressed: () {}, icon: const Icon(Icons.help)),
        ],
      ),
      body: Stack(
        //Parent stack
        children: [
          SizedBox(
            height: SizeConfig().screenHeight * 0.9,
            child: Column(
              mainAxisAlignment: MainAxisAlignment.end,
              children: [
                ElevatedButton(
                  onPressed: openFirstChild,
                  child: const Text('Proceed to EMI selection'),
                ),
              ],
            ),
          ),
          if (isFirstWidgetOpen)
            FirstChild(
              openSecondChild: openSecondChild,
              closeFirstChild: closeFirstChild,
            ),
          if (isSecondWidgetOpen)
            SecondChild(
              closeSecondChild: closeSecondChild,
            ),
        ],
      ),
    );
  }
}

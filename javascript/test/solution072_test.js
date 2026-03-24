var assert = require('assert');
var solution072 = require('../src/euler/solution072');

describe('Solution072', function() {
  describe('answer', function() {
    it('will answer problem 072', function() {
      assert.equal(solution072.answer(), 303963552391);
    });
  });
});
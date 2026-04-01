var assert = require('assert');
var solution091 = require('../src/euler/solution091');

describe('Solution091', function() {
  describe('answer', function() {
    it('will answer problem 091', function() {
      assert.equal(solution091.answer(), 14234);
    });
  });
});